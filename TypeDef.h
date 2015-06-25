#ifndef TYPEDEF_H
#define TYPEDEF_H
/*
	define the type
*/
typedef		int		SqListElemType;
typedef		int		LinkListElemType;
typedef     int     StackElemType;
typedef     int     QueueElemType;
typedef     int     BiTreeElemType;

enum LR {
    LEFT = 0,
    RIGHT = 1
};

/*
	define the MACRO
*/
#define		INIT_SIZE	    100
#define		INCREMENT	    10
#define     MAXELEMNUM      200


//ºê×´Ì¬
#define		OK				0
#define		OVER    		1
#define		ERROR			2


//ºê²Ù×÷
#define     MAX(a, b)       ((a) > (b) ? (a) : (b))
#define     MIN(a, b)       ((a) < (b) ? (a) : (b))
#define     ABS(a)          ((a) > 0 ? (a) : (-(a)));
#endif