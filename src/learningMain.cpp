#include <iostream>
#include "include.h"
#include "learningChapter2.h"
using namespace std;

int main() {
	CV_STATUS result = CV_ERR_OK;
	//result = Sample2_1("all_souls_000019.jpg");
	//result = Sample2_2("sports.avi");
	//result = Sample2_3("sports.avi");
	//result = Sample2_4("all_souls_000019.jpg");
	//result = Sample2_5("all_souls_000019.jpg");
	//result = Sample2_9();
	result = Sample2_10("sports.avi", "sports2.aiv");
	printf("CV_STATTUS CODE: %d\n", result);
	system("pause");
	return 0;
}