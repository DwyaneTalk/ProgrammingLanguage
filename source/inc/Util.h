#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <limits.h>

#include "TypeDef.h"


using namespace std;

// global variable externs
extern ifstream fin;
extern ofstream fout;
extern ofstream ferr;

// global function statements

void globalInit();

void* renew(void* base, int count, int inc, int size);

#endif 