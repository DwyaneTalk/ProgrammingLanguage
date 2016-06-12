#include "cv.h"
#include "highgui.h"
#include "learningChapter5.h"

CV_STATUS Sample5_smooth(const char* fileName) {
	if(!fileName || !strlen(fileName))	return CV_ERR_FILE;
	IplImage* iplImage = cvLoadImage(fileName, CV_LOAD_IMAGE_GRAYSCALE);
	if(!iplImage)	return CV_ERR_NULL;
	IplImage* showImage = cvCreateImage(cvSize(iplImage->widthStep, iplImage->height * 5), IPL_DEPTH_8U, 1);
	IplImage* blurImage = cvCreateImage(cvSize(iplImage->widthStep, iplImage->height), IPL_DEPTH_8U, 1);
	IplImage* meanImage = cvCreateImage(cvSize(iplImage->widthStep, iplImage->height), IPL_DEPTH_8U, 1);
	IplImage* gaussImage = cvCreateImage(cvSize(iplImage->widthStep, iplImage->height), IPL_DEPTH_8U, 1);
	IplImage* bilaImage = cvCreateImage(cvSize(iplImage->widthStep, iplImage->height), IPL_DEPTH_8U, 1);
	cvSmooth(iplImage, blurImage, CV_BLUR);
	cvSmooth(iplImage, meanImage, CV_MEDIAN);
	cvSmooth(iplImage, gaussImage, CV_GAUSSIAN);
	cvSmooth(iplImage, bilaImage, CV_BILATERAL);
	memcpy(showImage->imageData, iplImage->imageData, iplImage->imageSize);
	memcpy(showImage->imageData + iplImage->imageSize, blurImage->imageData, iplImage->imageSize);
	memcpy(showImage->imageData + iplImage->imageSize * 2, meanImage->imageData, iplImage->imageSize);
	memcpy(showImage->imageData + iplImage->imageSize * 3, gaussImage->imageData, iplImage->imageSize);
	memcpy(showImage->imageData + iplImage->imageSize * 4, bilaImage->imageData, iplImage->imageSize);
	cvNamedWindow("smooth image", CV_WINDOW_FREERATIO);
	cvShowImage("smooth image", showImage);
	cvWaitKey(0);
	cvDestroyWindow("smooth image");
	cvReleaseImage(&showImage);
	cvReleaseImage(&iplImage);
	return CV_ERR_OK;
}

CV_STATUS Sample5_morphology(const char* fileName) {
	if(!fileName || !strlen(fileName))	return CV_ERR_FILE;
	IplImage* iplImageNew, *iplImageOri, *iplImageTmp, *iplImageShow;
	iplImageOri = cvLoadImage(fileName, CV_LOAD_IMAGE_GRAYSCALE);
	if(!iplImageOri)	return CV_ERR_NULL;
	iplImageTmp = cvCreateImage(cvSize(iplImageOri->width, iplImageOri->height), IPL_DEPTH_8U, 1);
	if(!iplImageTmp){
		cvReleaseImage(&iplImageOri);	return CV_ERR_NULL;
	}
	iplImageNew = cvCreateImage(cvSize(iplImageOri->width, iplImageOri->height), IPL_DEPTH_8U, 1);
	if(!iplImageNew) {
		cvReleaseImage(&iplImageOri);
		cvReleaseImage(&iplImageTmp);
		return CV_ERR_NULL;
	}
	iplImageShow = cvCreateImage(cvSize(iplImageOri->width, iplImageOri->height * 3), IPL_DEPTH_8U, 1);
	if(!iplImageShow) {
		cvReleaseImage(&iplImageOri);
		cvReleaseImage(&iplImageTmp);
		cvReleaseImage(&iplImageNew);
		return CV_ERR_NULL;
	}
	cvNamedWindow("morphology", CV_WINDOW_FREERATIO);
	int count = 0;
	while(1) {
		switch(count++ % 8) {
		case 0: cvCopy(iplImageOri, iplImageNew);	cvCopy(iplImageOri, iplImageTmp); printf("Ô­Ê¼Í¼Ïñ\n"); break;
		case 1: cvErode(iplImageOri, iplImageNew);	cvCopy(iplImageOri, iplImageTmp); printf("¸¯Ê´²Ù×÷\n");break;
		case 2: cvDilate(iplImageOri, iplImageNew); cvCopy(iplImageOri, iplImageTmp); printf("ÅòÕÍ²Ù×÷\n");break;
		case 3: cvMorphologyEx(iplImageOri, iplImageNew, iplImageTmp, NULL, CV_MOP_OPEN); printf("¿ª²Ù×÷\n");break;
		case 4: cvMorphologyEx(iplImageOri, iplImageNew, iplImageTmp, NULL, CV_MOP_CLOSE); printf("±Õ²Ù×÷\n");break;
		case 5: cvMorphologyEx(iplImageOri, iplImageNew, iplImageTmp, NULL, CV_MOP_GRADIENT); printf("ÌÝ¶È²Ù×÷\n");break;
		case 6: cvMorphologyEx(iplImageOri, iplImageNew, iplImageTmp, NULL, CV_MOP_TOPHAT); printf("ÀñÃ±²Ù×÷\n");break;
		case 7: cvMorphologyEx(iplImageOri, iplImageNew, iplImageTmp, NULL, CV_MOP_BLACKHAT); printf("ºÚÃ±²Ù×÷\n");break;
		}
		memcpy(iplImageShow->imageData, iplImageOri->imageData, iplImageOri->imageSize);
		memcpy(iplImageShow->imageData + iplImageOri->imageSize, iplImageNew->imageData, iplImageOri->imageSize);
		memcpy(iplImageShow->imageData + iplImageOri->imageSize * 2, iplImageTmp->imageData, iplImageOri->imageSize);
		cvShowImage("morphology", iplImageShow);
		if(cvWaitKey(0) == 27)	break;
	}
	cvDestroyWindow("morphology");
	cvReleaseImage(&iplImageShow);
	cvReleaseImage(&iplImageOri);
	cvReleaseImage(&iplImageNew);
	cvReleaseImage(&iplImageTmp);
	return CV_ERR_OK;
}


void floodFillMouseCallBack(int event, int x, int y, int flags, void* params) {
	if(event == CV_EVENT_FLAG_LBUTTON) {
		IplImage* iplImage = (IplImage*)params;
		IplImage* iplImageShow = cvCloneImage(iplImage);
		cvFloodFill(iplImageShow, cvPoint(x, y), cvScalar(255), cvScalar(9), cvScalar(9), NULL, CV_FLOODFILL_FIXED_RANGE);
		cvShowImage("floodFill", iplImageShow);
		cvReleaseImage(&iplImageShow);
	}
}
CV_STATUS Sample5_floodFill(const char* fileName) {
	if(!fileName || !strlen(fileName))	return CV_ERR_FILE;
	IplImage *iplImageOri = cvLoadImage(fileName, CV_LOAD_IMAGE_GRAYSCALE);
	if(!iplImageOri)	return CV_ERR_NULL;
	cvNamedWindow("floodFill");
	cvSetMouseCallback("floodFill", floodFillMouseCallBack, (void*)iplImageOri);
	cvShowImage("floodFill", iplImageOri);
	while(1){
		if(cvWaitKey(0) == 27)	break;
	}
	cvDestroyWindow("floodFill");
	cvReleaseImage(&iplImageOri);
	return CV_ERR_OK;
}

CV_STATUS Sample5_pyramid(const char* fileName) {
	if(!fileName || !strlen(fileName))	return CV_ERR_NULL;
	IplImage* iplImageOri = cvLoadImage(fileName, CV_LOAD_IMAGE_GRAYSCALE);
	if(!iplImageOri)	return CV_ERR_NULL;
	IplImage* gaussImage[5] = {NULL}, *laplaceImage[4] = {NULL};
	IplImage* gaussShow = cvCreateImage(cvSize(iplImageOri->width, iplImageOri->height * 2), IPL_DEPTH_8U, 1);
	IplImage* laplaceShow = cvCreateImage(cvSize(iplImageOri->width, iplImageOri->height * 2), IPL_DEPTH_8U, 1);
	cvZero(gaussShow);
	cvZero(laplaceShow);
	cvSetImageROI(gaussShow, cvRect(0, 0, iplImageOri->width, iplImageOri->height));
	cvSetImageROI(laplaceShow, cvRect(0, 0, iplImageOri->width, iplImageOri->height));
	cvCopyImage(iplImageOri, gaussShow);
	cvCopyImage(iplImageOri, laplaceShow);
	gaussImage[0] = cvCreateImage(cvSize(iplImageOri->width / 2, iplImageOri->height / 2), IPL_DEPTH_8U, 1);
	cvPyrDown(iplImageOri, gaussImage[0]);
	for(int i = 0, height = 0; i < 4; ++i) {
		IplImage* tmpImage = cvCreateImage(cvGetSize(gaussImage[i]), IPL_DEPTH_8U, 1);
		gaussImage[i + 1] = cvCreateImage(cvSize(gaussImage[i]->width / 2, gaussImage[i]->height / 2), IPL_DEPTH_8U, 1);
		laplaceImage[i] = cvCreateImage(cvGetSize(gaussImage[i]), IPL_DEPTH_8U, 1);
		cvPyrDown(gaussImage[i], gaussImage[i + 1]);
		cvPyrUp(gaussImage[i + 1], tmpImage);
		cvAbsDiff(gaussImage[i], tmpImage, laplaceImage[i]);
		height += gaussImage[i]->height * 2;
		cvSetImageROI(gaussShow, cvRect(0, height, gaussImage[i]->width, gaussImage[i]->height));
		cvSetImageROI(laplaceShow, cvRect(0, height, gaussImage[i]->width, gaussImage[i]->height));
		cvCopyImage(gaussImage[i], gaussShow);
		cvCopyImage(laplaceImage[i], laplaceShow);
		cvReleaseImage(&tmpImage);
		cvReleaseImage(&gaussImage[i]);
		cvReleaseImage(&laplaceImage[i]);
	}
	cvReleaseImage(&gaussImage[4]);
	cvResetImageROI(gaussShow);
	cvResetImageROI(laplaceShow);
	cvNamedWindow("gauss pyramid", CV_WINDOW_FREERATIO);
	cvNamedWindow("laplace pyramid", CV_WINDOW_FREERATIO);
	cvShowImage("gauss pyramid", gaussShow);
	cvShowImage("laplace pyramid", laplaceShow);
	while(1) {
		if(cvWaitKey(0) == 27)	break;
	}
	cvDestroyWindow("gauss pyramid");
	cvDestroyWindow("laplace pyramid");
	cvReleaseImage(&iplImageOri);
	return CV_ERR_OK;
}
