#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef     signed char         Int8;
typedef     unsigned char       UInt8;
typedef     signed  short       Int16;
typedef     unsigned short      UInt16;
typedef     signed  int         Int32;
typedef     unsigned int        UInt32;
typedef     signed long         Int64;
typedef     unsigned long       UInt64;
typedef     bool                Bool;

/*
	define the elemtype
*/
typedef		int		SqListElemType;
typedef		int		LinkListElemType;
typedef     int     StackElemType;
typedef     int     QueueElemType;
typedef     int     BiTreeElemType;
typedef     int     TreeElemType;
typedef     char    VexType;
typedef     int     ArcType;

enum LR {
    LEFT = 0,
    RIGHT = 1
};

enum GType {
    DG  = 0,    //有向无权图
    DN  = 1,    //有向带权图(网)
    UDG = 2,    //无向无权图
    UDN = 3     //无向带权图
};

/*
	define the MACRO
*/
#define		INIT_SIZE	    100
#define		INCREMENT	    10
#define     MAXELEMNUM      200

#define     MAX_ARC         INT_MAX

//宏状态
#define		OK				0
#define		OVER    		1
#define		ERROR			2


//宏操作
#define     MAX(a, b)       ((a) > (b) ? (a) : (b))
#define     MIN(a, b)       ((a) < (b) ? (a) : (b))
#define     ABS(a)          ((a) > 0 ? (a) : (-(a)));
#endif