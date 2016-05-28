#pragma once

#include "include.h"

/************ show a image ************/
CV_STATUS Sample2_1(const char* imgName);		

/************ display a video ************/
CV_STATUS Sample2_2(const char* fileName);		

/************ video display control ************/
CV_STATUS Sample2_3(const char* fileName);		

/************ smooth image with 3x3 gaussian kernel ************/
CV_STATUS Sample2_4(const char* fileName);		

/************ PyrDown and Canny ************/
CV_STATUS Sample2_5(const char* fileName);		

/************ display video from camara ************/
CV_STATUS Sample2_9(int idx = -1);				

/************ read video in file, down sample and restore in file ************/
CV_STATUS Sample2_10(const char* srcName, const char* dstName);		