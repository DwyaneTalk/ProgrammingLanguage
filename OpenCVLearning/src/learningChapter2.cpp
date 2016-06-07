#include "highgui.h"
#include "cv.h"
#include "learningChapter2.h"

/************ show a image ************/
CV_STATUS Sample2_1(const char* fileName) {
	IplImage* iplImage = cvLoadImage(fileName);
	if(!iplImage)	return CV_ERR_FILE;
	cvNamedWindow("Sample2_1");
	cvShowImage("Sample2_1", iplImage);
	cvWaitKey(0);
	cvDestroyWindow("Sample2_1");
	cvReleaseImage(&iplImage);
	return CV_ERR_OK;
}

/************ display a video ************/
CV_STATUS Sample2_2(const char* fileName) {
	CvCapture* capture = cvCreateFileCapture(fileName);
	if(!capture)	return CV_ERR_FILE;
	cvNamedWindow("Sample2_2");
	IplImage* iplImage = NULL;
	while (iplImage = cvQueryFrame(capture)) {
		cvShowImage("Sample2_2", iplImage);
		char ch = cvWaitKey(33);
		if(ch == 27)	break;
	}
	cvDestroyWindow("Sample2_2");
	cvReleaseCapture(&capture);
	return CV_ERR_OK;
}

/************ video display control ************/
CvCapture*	capture	= NULL;
void onTrackBarSlide(int pos) {
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}
CV_STATUS Sample2_3(const char* fileName) {
	capture = cvCreateFileCapture(fileName);
	if(!capture)	return CV_ERR_FILE;
	cvNamedWindow("Sample2_3");
	int numFrame = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT), posFrame = 0;
	if(!numFrame)	return CV_ERR_NULL;
	cvCreateTrackbar("Position", "Sample2_3", &posFrame, numFrame, onTrackBarSlide);
	IplImage* iplImage = NULL;
	while(iplImage = cvQueryFrame(capture)) {
		cvShowImage("Sample2_3", iplImage);
		char ch = cvWaitKey(33);
		if(ch == 27)	break;
	}
	cvDestroyWindow("Sample2_3");
	cvReleaseCapture(&capture);
	return CV_ERR_OK;
}

/************ smooth image with 3x3 gaussian kernel ************/
CV_STATUS Sample2_4(const char* fileName) {
	IplImage* iplImage = cvLoadImage(fileName);
	if(!iplImage)	return CV_ERR_FILE;
	IplImage* iplImageOut = cvCreateImage(cvGetSize(iplImage), iplImage->depth, iplImage->nChannels);
	cvNamedWindow("Sample2_4-in");
	cvNamedWindow("Sample2_4-out");
	cvSmooth(iplImage, iplImageOut, CV_GAUSSIAN, 3, 3);
	cvShowImage("Sample2_4-in", iplImage);
	cvShowImage("Sample2_4-out", iplImageOut);
	cvWaitKey(0);
	cvDestroyWindow("Sample2_4-out");
	cvDestroyWindow("Sample2_4-in");
	cvReleaseImage(&iplImageOut);
	cvReleaseImage(&iplImage);
	return CV_ERR_OK;
}

/************ PyrDown and Canny ************/
IplImage* doPyrDown(IplImage* iplImageIn, double factor) {
	if(!iplImageIn)	return NULL;
	IplImage* iplImageOut = cvCreateImage(cvSize(int(iplImageIn->width * factor), int(iplImageIn->height * factor)), iplImageIn->depth, iplImageIn->nChannels);
	if(iplImageOut)	cvPyrDown(iplImageIn, iplImageOut);
	cvReleaseImage(&iplImageIn);
	return iplImageOut;
}
IplImage* doCvtColor(IplImage* iplImageIn) {
	if(!iplImageIn || iplImageIn->nChannels != 3)	return NULL;
	IplImage* iplImageOut = cvCreateImage(cvGetSize(iplImageIn), IPL_DEPTH_8U, 1);
	if(iplImageOut)	cvCvtColor(iplImageIn, iplImageOut, CV_BGR2GRAY);
	return iplImageOut;
}
IplImage* doCanny(IplImage* iplImageIn, double loThresh, double hiThresh, int aperture) {
	if(!iplImageIn || iplImageIn->nChannels != 1)	return NULL;
	IplImage* iplImageOut = cvCreateImage(cvGetSize(iplImageIn), iplImageIn->depth, iplImageIn->nChannels);
	if(iplImageOut)	cvCanny(iplImageIn, iplImageOut, loThresh, hiThresh, aperture);
	cvReleaseImage(&iplImageIn);
	return iplImageOut;
}
CV_STATUS Sample2_5(const char* fileName) {
	IplImage* iplImage = cvLoadImage(fileName), *iplImageOut = NULL;
	if(!iplImage)	return CV_ERR_FILE;
	cvNamedWindow("Sample2_5");
	cvShowImage("Sample2_5", iplImage);
	cvWaitKey(0);
	iplImageOut = doPyrDown(iplImage, 0.5);
	cvShowImage("Sample2_5", iplImageOut);
	cvWaitKey(0);
	iplImageOut = doCvtColor(iplImageOut);
	cvShowImage("Sample2_5", iplImageOut);
	cvWaitKey(0);
	iplImageOut = doCanny(iplImageOut, 10, 100, 3);
	cvShowImage("Sample2_5", iplImageOut);
	cvWaitKey(0);
	cvDestroyWindow("Sample2_5");
	cvReleaseImage(&iplImageOut);
	return CV_ERR_OK;
}

/************ display video from camara ************/
CV_STATUS Sample2_9(int idx) {
	CvCapture* capture = cvCreateCameraCapture(idx);
	if(!capture)	return CV_ERR_CAM;
	IplImage* iplImage = NULL;
	while(iplImage = cvQueryFrame(capture)) {
		cvShowImage("Sample2_9", iplImage);
		char ch = cvWaitKey(33);
		if(ch == 27)	break;
	}
	cvNamedWindow("Sample2_9");
	cvDestroyWindow("Sample2_9");
	cvReleaseCapture(&capture);
	return CV_ERR_OK;
}

/************ read video in file, down sample and restore in file ************/
CV_STATUS Sample2_10(const char* srcName, const char* dstName) {
	CvCapture* capture = cvCreateFileCapture(srcName);
	if(!capture)	return CV_ERR_FILE;
	double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	int width  = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	int height = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	CvSize size = cvSize(width >> 1, height >> 1);
	CvVideoWriter* writer = cvCreateVideoWriter(dstName, CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	if(!writer)	return CV_ERR_FILE;
	cvNamedWindow("Sample2_10");

	IplImage* iplImage = NULL;
	IplImage* iplImageOut = cvCreateImage(size, IPL_DEPTH_8U, 3);
	while(iplImage = cvQueryFrame(capture)) {
		cvShowImage("Sample2_10", iplImage);
		cvPyrDown(iplImage, iplImageOut);
		cvWriteFrame(writer, iplImageOut);
		char ch = cvWaitKey(30);
		if(ch == 27)	break;
	}
	cvReleaseImage(&iplImageOut);
	cvDestroyWindow("Sample2_10");
	cvReleaseCapture(&capture);
	return CV_ERR_OK;
}