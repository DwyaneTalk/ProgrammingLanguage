#include "cv.h"
#include "highgui.h"
#include "learningChapter4.h"

/************ show an image on a named window ************/
CV_STATUS Sample4_0(const char* fileName) {
    if(!fileName || !strlen(fileName))  return CV_ERR_FILE;
    cvNamedWindow(fileName, CV_WINDOW_KEEPRATIO);
    IplImage* iplImage = cvLoadImage(fileName, CV_LOAD_IMAGE_COLOR);
    if(!iplImage)   return CV_ERR_NULL;
    void* handle = cvGetWindowHandle(fileName);
    const char* winName = cvGetWindowName(handle);
    cvShowImage(winName, iplImage);
    int x =  100, y = 100, width = iplImage->width, height = iplImage->height;
    cvMoveWindow(winName, x, y);
    cvResizeWindow(winName, width, height);
    while (1) {
        int ch = cvWaitKey(100);
        if(ch == 27) {
            break;
        } else {
            switch(ch) {
            case '2': y += 10; break;
            case '8': y -= 10; break;
            case '4': x -= 10; break;
            case '6': x += 10; break;
            case '1': width *= 1.2; height *= 1.2; break;
            case '3': width *= 0.8; height *= 0.8; break;
            }
            cvMoveWindow(winName, x, y);
            cvResizeWindow(winName, width, height);
        }
    }
    cvReleaseImage(&iplImage);
    cvDestroyWindow(fileName);
    return CV_ERR_OK;
}

/************ draw rectangle using mouse ************/
typedef struct {
    bool    bDown;
    CvRect  box;
    IplImage* img;
    IplImage* imgBack;
} Params;
void drawBox(IplImage* img, IplImage* imgBack, CvRect box) {
    if(box.width < 0) {
        box.x += box.width;
        box.width *= (-1);
    }
    if(box.height < 0) {
        box.y += box.height;
        box.height *= (-1);
    }
    cvCopyImage(imgBack, img);
    cvRectangle(img, cvPoint(box.x, box.y), cvPoint(box.x + box.width, box.y + box.height), cvScalar(255.0, 0.0, 0.0));
}
void mouseCallBack(int event, int x, int y, int flags, void* param) {
    Params* params = (Params*) param;
    switch(event) {
    case CV_EVENT_LBUTTONDOWN:  params->bDown = true; params->box = cvRect(x, y, 0, 0); break;
    case CV_EVENT_MOUSEMOVE:    
        if(params->bDown) {
            params->box.width = x - params->box.x;
            params->box.height = y - params->box.y;
            drawBox(params->img, params->imgBack, params->box);
        }
        break;
    case CV_EVENT_LBUTTONUP:    params->bDown = false;
        drawBox(params->img, params->imgBack, params->box);
        cvCopyImage(params->img, params->imgBack);
        break;
    }
}
CV_STATUS Sample4_1() {
    Params params;
    params.bDown = false;
    params.box  = cvRect(-1, -1, 0, 0);
    params.img = cvCreateImage(cvSize(600, 400), IPL_DEPTH_8U, 3);
    params.imgBack = cvCloneImage(params.img);
    if(!params.img || !params.imgBack) return CV_ERR_NULL;
    cvZero(params.imgBack);
    cvCopyImage(params.imgBack, params.img);
    cvNamedWindow("draw window");
    cvShowImage("draw window", params.img);
    cvSetMouseCallback("draw window", mouseCallBack, (void*)&params);
    while(1) {
        int ch = cvWaitKey(10);
        if(ch == 27)    break;
        if(ch == '0') {
            cvZero(params.imgBack);        
            cvCopyImage(params.imgBack, params.img);
        }
        cvShowImage("draw window", params.img);
    }
    cvDestroyWindow("draw window");
    cvReleaseImage(&params.img);
    return CV_ERR_OK;
}

/*******************implement button using slider*******/
void trackBarCallBack(int cur_pos) {}
CV_STATUS Sample4_2() {
    IplImage* colorLenaImg = cvLoadImage("lena_color.jpg", 1);
    if(!colorLenaImg)   return CV_ERR_NULL;
    IplImage* grayLenaImg = cvLoadImage("lena_gray.jpg");
    if(!grayLenaImg)   return CV_ERR_NULL;
    int cur_pos = 0;
    cvNamedWindow("button");

    cvCreateTrackbar("slider", "button", &cur_pos, 1, trackBarCallBack);
    while(1) {
        if(cvWaitKey(10) == 27) break;
        if(cur_pos)     cvShowImage("button", colorLenaImg);
        else            cvShowImage("button", grayLenaImg);
    }

    cvDestroyWindow("button");
    cvReleaseImage(&colorLenaImg);
    cvReleaseImage(&grayLenaImg);
    return CV_ERR_OK;
}