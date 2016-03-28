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
CV_STATUS Sample3_1to3() {
    int     cols = 10, rows = 20;
    int     type = CV_8UC1;
    void*   pointer = NULL;
    // create CvMat (CvMatHeader and CvMatData)
    CvMat   mat0    = cvMat(rows, cols, type, pointer);             //allocate mat header and init data to pointer
    CvMat*  mat1    = cvCreateMat(rows, cols, type);                //allocate mat header and data
    CvMat*  mat2    = cvCreateMatHeader(rows, cols, type);          //allocate mat header and init data to NULL
                      cvCreateData(mat2);                           //allocate mat data for mat2
    CvMat*  mat3    = cvCloneMat(mat1);                             //clone a mat from mat1, then mat1->data and mat3->data point to the same space
    CvMat*  mat     = cvInitMatHeader(mat1, rows + 1, cols + 1, type);  //re-init mat1 header and init data to pointer, then mat1 and mat point to the same space
    cvReleaseMat(&mat2);                                            //free mat header and data, theh mat2 is NULL
    cvReleaseMat(&mat3);
    printf("CvMat Init-> rows : %d, cols : %d, type : %d, step : %d\n", mat->rows, mat->cols, mat->type, mat->step);

    // get CvMat size
    CvSize size = cvGetSize(mat);               //get mat size
    type = cvGetElemType(mat);                  //get mat type
    int dimSize[2];
    int dimNums = cvGetDims(mat, dimSize);      //get mat dimensions in dimNums and size of each dimensions in dimSize
    printf("CvMat Size-> rows : %d, cols : %d, type : %d, numDims : %d, DimSize0 : %d, DimSize1 : %d\n", size.height, size.width, type, dimNums, dimSize[0], dimSize[1]);

    // CvMat read and write
    return CV_ERR_OK;
}