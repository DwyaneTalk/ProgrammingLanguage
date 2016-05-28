#pragma once

typedef enum CV_ERR_CODES{
	CV_ERR_OK		=	0,
	CV_ERR_NULL		=	1,
	CV_ERR_FILE		=	2,
	CV_ERR_CAM		=	3,
} CV_STATUS;


#define G_WEIGHT    0.587
#define B_WEIGHT    0.114
#define R_WEIGHT    0.299