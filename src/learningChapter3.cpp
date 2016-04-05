#include "highgui.h"
#include "learningChapter3.h"

/************ basic data type in OpenCV ************/
CV_STATUS Sample3_0 () {
    int     xInt = 5,   yInt = 5,   zInt = 5;
    int     wInt = 5,   hInt = 5;
    double  x32f = 5.0, y32f = 5.0, z32f = 5.0;
    double  w32f = 5.0, h32f = 5.0;
    double  scalar0 = 0.0, scalar1 = 1.0, scalar2 = 2.0, scalar3 = 3.0;

    CvPoint         point       = cvPoint(xInt, yInt);
    CvPoint2D32f    point2D32f  = cvPoint2D32f(x32f, y32f);
    CvPoint3D32f    point3D32f  = cvPoint3D32f(x32f, y32f, z32f);
    printf("CvPoint-> x : %d, y: %d\n", point.x, point.y);
    printf("CvPoint2D32f-> x : %f, y : %f\n", point2D32f.x, point2D32f.y);
    printf("CvPoint3D32f-> x : %f, y : %f, z : %f\n", point3D32f.x, point3D32f.y, point3D32f.z);

    CvSize          size        = cvSize(wInt, hInt);
    CvSize2D32f     size2D32f   = cvSize2D32f(w32f, h32f);
    printf("CvSize-> width : %d, height : %d\n", size.width, size.height);
    printf("CvSize2D32f-> width : %f, height : %f\n", size2D32f.width, size2D32f.height);

    CvRect          rect        = cvRect(xInt, yInt, wInt, hInt);
    CvScalar        scalar      = cvScalar(scalar0, scalar1, scalar2, scalar3);
    CvScalar        scalarAll   = cvScalarAll(scalar3);
    CvScalar        scalarReal  = cvRealScalar(scalar3);
    printf("CvRect-> x : %d, y : %d, width : %d, height : %d\n", rect.x, rect.y, rect.width, rect.height);
    printf("CvScaler-> s0 : %f, s1 : %f, s2 : %f, s3 : %f\n", scalar.val[0], scalar.val[1], scalar.val[2], scalar.val[3]);
    printf("CvScalerAll-> s0 : %f, s1 : %f, s2 : %f, s3 : %f\n", scalarAll.val[0], scalarAll.val[1], scalarAll.val[2], scalarAll.val[3]);
    printf("CvScalerReal-> s0 : %f, s1 : %f, s2 : %f, s3 : %f\n", scalarReal.val[0], scalarReal.val[1], scalarReal.val[2], scalarReal.val[3]);

    IplImage* iplImage = cvLoadImage("all_souls_000013.jpg");
    if(!iplImage)   return CV_ERR_FILE;
    cvRectangle(iplImage, cvPoint(iplImage->width / 3, iplImage->height / 3), cvPoint(iplImage->width / 3 * 2, iplImage->height / 3 * 2), cvScalar(255, 0, 0), 3);
    cvNamedWindow("ShowImage");
    cvShowImage("ShowImage", iplImage);
    cvWaitKey(0);
    cvDestroyWindow("ShowImage");
    cvReleaseImage(&iplImage);

    return CV_ERR_OK;
}

/************ CvMat and IplImage in OpenCV ************/
//CvArr: abstract base type,    CvArr -> CvMat -> IplImage
//typedef void CvArr
//typedef struct CvMat {            //consist of MatData(data) and MatHeader(others)
//  int type;                       //CV_<bit-depth>(S|U|F)C<channels-num>, like: CV_8UC3¡¢CV_32FC1
//  int step;                       //line buffer size in byte
//  union {¡­}data;                  //pointer to the mat data
//  union {int rows; int height;};
//  union {int cols; int width;};
//} CvMat;
//typedef struct IplImage {
//  int     nSize;                  //sizeof(IplImage)
//  int     ID;                     //version(=0)
//  int     nChannels;              //number of channels, 3 for RGB image
//  int     depth;                  //Pixel depth in bits, generally 8
//  int     dataOrder;              //IPL_DATA_ORDER_PIEXL(RGBRGBRGB) and IPL_DATA_ORDER_PLANE(ont support in opencv)
//  int     origin;                 //IPL_ORIGIN_TL(origion point in the top-left) and IPL_ORIGIN_BL(origion point in the bottom-left)
//  int     align;                  //alignment for a line row(4 or 8 supported)
//  int     width;                  //image width
//  int     height;                 //image height
//  struct _IplROI* roi;            //region of intrest(if set, all operation ot image only in this region)
//  int     imageSize;              //height * imageStep
//  char*   imageData;              //data
//  int     imageStep;              //aligned line buffer size
//  ¡­¡­                              //other data
//};
/************ CvMat create¡¢init and release ************/
CV_STATUS Sample3_1to3() {
    int     cols = 10, rows = 20;
    int     type = CV_8UC1;
    void*   pointer = NULL;
    // create CvMat (CvMatHeader and CvMatData)
    CvMat   mat0    = cvMat(rows, cols, type, pointer);             //allocate mat header and init data to pointer
    CvMat*  mat1    = cvCreateMat(rows, cols, type);                //allocate mat header and data
    if(!mat1)       return CV_ERR_NULL;
    CvMat*  mat2    = cvCreateMatHeader(rows, cols, type);          //allocate mat header and init data to NULL
    if(!mat2)       return CV_ERR_NULL;
                      cvCreateData(mat2);                           //allocate mat data for mat2
    CvMat*  mat3    = cvCloneMat(mat1);                             //clone a mat from mat1, then mat1->data and mat3->data point to the same space
    if(!mat3)       return CV_ERR_NULL;
    CvMat*  mat     = cvInitMatHeader(mat1, rows + 1, cols + 1, type);  //re-init mat1 header and init data to pointer, then mat1 and mat point to the same space
    if(!mat || !mat1)   return CV_ERR_NULL;
    cvReleaseMat(&mat2);                                            //free mat header and data, theh mat2 is NULL
    cvReleaseMat(&mat3);
    printf("CvMat Init-> rows : %d, cols : %d, type : %d, step : %d\n", mat->rows, mat->cols, mat->type, mat->step);

    // get CvMat size
    CvSize size = cvGetSize(mat);               //get mat size
    type = cvGetElemType(mat);                  //get mat type
    int dimSize[2];
    int dimNums = cvGetDims(mat, dimSize);      //get mat dimensions in dimNums and size of each dimensions in dimSize
    printf("CvMat Size-> rows : %d, cols : %d, type : %d, numDims : %d, DimSize0 : %d, DimSize1 : %d\n", size.height, size.width, type, dimNums, dimSize[0], dimSize[1]);
    return CV_ERR_OK;
}
/************ CvMat read and write ************/
CV_STATUS Sample3_4to9() {
    int cols = 5, rows = 5;
    int type = CV_32SC1;
    CvMat*  mat =   cvCreateMat(rows, cols, type);
    if(!mat)    return CV_ERR_NULL;
    int*    elemPtr =   (int*)CV_MAT_ELEM_PTR(*mat, 2, 3);      //Macro for get the elem val, only for 1 or 2 dimension Mat
    if(!elemPtr)    return CV_ERR_NULL;
    *elemPtr    = 10;        
    int     elemVal =   CV_MAT_ELEM(*mat, int, 2, 3);           //Macro for get the elem ptr, only for 1 or 2 dimension Mat
    printf("set elemVal for 1 or 2 dimension Mat-> %d\n", elemVal);

    int dims = 3, dimSize[3] = {2, 3, 4};                       
    CvMatND* matND  =   cvCreateMatND(dims, dimSize, type);         //create multi-dimension Mat with dimension size in dimSize
    int* elemNDPtr  =   (int*)cvPtr3D(matND, 1, 2, 3);              //get the elem ptr for multi(3) dimension mat
    if(!elemNDPtr)  return CV_ERR_NULL;
    *elemNDPtr  =   20;
    int elemNDVal   =   (int)cvGetReal3D(matND, 1, 2, 3);           //get the elem val(double) for multi(3) dimension mat
    CvScalar scalar =   cvGet3D(matND, 1, 2, 3);                    //get the elem val(Scalar) for multi(3) dimension mat
    printf("set elemVal for multi-dimension Mat-> %d\n", elemNDVal);
    printf("set elemVal for multi-dimension Mat-> scalar0 : %d, scalar1 : %d, scalar2 : %d, scalar3 : %d\n", (int)scalar.val[0], (int)scalar.val[1], (int)scalar.val[2], (int)scalar.val[3]);
    cvSet3D(matND, 1, 2, 3, cvScalar(1.0, 2.0, 3.0, 4.0));          //set the elem val(double) for multi(3) dimension mat
    printf("set elemVal for multi-dimension Mat-> %d\n", (int)cvGetReal3D(matND, 1, 2 ,3));
    cvSetReal3D(matND, 1, 2, 3, 5.0);                               //set the elem val(Scalar) for multi(3) dimension mat
    printf("set elemVal for multi-dimension Mat-> %d\n", (int)cvGetReal3D(matND, 1, 2, 3));

    for(int irow = 0; irow < mat->rows; ++irow) {
        int* pointer = (int*)(mat->data.ptr + mat->step * irow);
        for(int icol = 0; icol < mat->cols; ++icol) {
            *pointer++ = irow * mat->cols + icol;
        }
    }
    for(int irow = 0; irow < mat->rows; ++irow) {
        const int* pointer = (const int*)(mat->data.ptr + mat->step * irow);
        printf("rows%d->", irow);
        for(int icol = 0; icol < mat->cols; ++icol) {
            printf("%3d", *pointer++);
        }
        printf("\n");
    }
    cvReleaseMat(&mat);
    cvReleaseMatND(&matND);

    return CV_ERR_OK;
}
/************ IplImage create and ROI ************/
IplImage* RGB2Gray(IplImage* iplImageIn) {
    IplImage* iplImageNew = cvCreateImage(cvGetSize(iplImageIn), iplImageIn->depth, 1); //create image with allocating data memory
    for(int irow = 0; irow < iplImageIn->height; ++irow) {
        unsigned char* srcPtr = (unsigned char*)iplImageIn->imageData + irow * iplImageIn->widthStep;
        unsigned char* dstPtr = (unsigned char*)iplImageNew->imageData + irow * iplImageNew->widthStep;
        for(int icol = 0; icol < iplImageIn->widthStep; icol += iplImageIn->nChannels) {    //widthstep may be not width * nchannels
            unsigned char val = srcPtr[icol] * G_WEIGHT + srcPtr[icol + 1] * B_WEIGHT + srcPtr[icol + 2] * R_WEIGHT;
            dstPtr[icol / iplImageIn->nChannels] = val;
        }
    }
    return iplImageNew;
}

void ROIAddS(IplImage* iplImageIn, CvScalar scalar, CvRect rect) {
    IplImage* iplImageSub = cvCreateImageHeader(cvSize(rect.width, rect.height), iplImageIn->depth, iplImageIn->nChannels);//create image header without allocating memory
    iplImageSub->dataOrder = iplImageIn->dataOrder;
    iplImageSub->origin = iplImageIn->origin;
    iplImageSub->widthStep = iplImageIn->widthStep;
    iplImageSub->imageData = iplImageIn->imageData + iplImageIn->widthStep * rect.y + rect.x * iplImageIn->nChannels;
    cvAddS(iplImageSub, scalar, iplImageSub);
    cvReleaseImageHeader(&iplImageSub);
}

CV_STATUS Sample3_10to13() {
    IplImage* iplImage = cvLoadImage("koala.jpg"), *iplImageNew = NULL;     //load image
    if(!iplImage)   return CV_ERR_NULL;
    if(!strcmp(iplImage->colorModel, "RGB")) iplImageNew = RGB2Gray(iplImage);  //determine the RGB image
    if(!iplImageNew)    return CV_ERR_NULL;
    cvNamedWindow("show image");
    CvRect rect = cvRect(iplImage->width / 4, iplImage->height / 4, iplImage->width / 2, iplImage->height / 2);
    cvSetImageROI(iplImage, rect);                  //set ROI
    cvAddS(iplImage, cvScalar(50), iplImage);       //all operation will be applied in the roi 
    cvShowImage("show image", iplImage);
    cvWaitKey(0);
    cvResetImageROI(iplImage);
    cvShowImage("show image", iplImage);
    cvWaitKey(0);
    cvShowImage("show image", iplImageNew);
    cvWaitKey(0);
    ROIAddS(iplImageNew, cvScalar(50), rect);
    cvShowImage("show image", iplImageNew);
    cvWaitKey(0);
    cvDestroyWindow("show image");
    cvReleaseImage(&iplImageNew);
    cvReleaseImage(&iplImage);
    return CV_ERR_OK;
}

