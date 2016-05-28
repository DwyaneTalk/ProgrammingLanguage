#include <iostream>
#include "include.h"
#include "learningChapter2.h"
#include "learningChapter3.h"
using namespace std;

int main() {
	CV_STATUS result = CV_ERR_OK;
#pragma region Chapter2
	//result = Sample2_1("all_souls_000019.jpg");
	//result = Sample2_2("sports.avi");
	//result = Sample2_3("sports.avi");
	//result = Sample2_4("all_souls_000019.jpg");
	//result = Sample2_5("all_souls_000019.jpg");
	//result = Sample2_9();
	//result = Sample2_10("sports.avi", "sports2.aiv");
#pragma endregion Chapter2

#pragma region Chapter3
    //result = Sample3_0();
    //result = Sample3_1to3();
    //result  = Sample3_4to9();
    result  = Sample3_10to13();
#pragma endregion Chapter3
	printf("CV_STATTUS CODE: %d\n", result);
	system("pause");
	return 0;
}