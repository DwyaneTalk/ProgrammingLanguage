#include "../inc/Util.h"
//global variables
ifstream fin;
ofstream fout;
ofstream ferr;

// global functions
void globalInit() {
    fin.open("input.txt");
    fout.open("output.txt");
    ferr.open("error.txt");
    ferr << "runtime error log start¡­¡­" << endl;
}

void* renew(void* base, int count, int inc, int size) {
    void* new_base;
    if (new_base = new UInt8[(count + inc) * size]) {
        memcpy(new_base, base, count * size);
        return new_base;
    } else {
        ferr << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
        exit(OVER);
    }
}

UInt32 getMin(UInt32 *array, UInt32 nums, UInt32 *index) {
    UInt32 min_value = *array;
    for (UInt32 i = 1; i < nums; ++i) {
        if (*(array + i) < min_value) {
            min_value = *(array + i);
            *(index) = i;
        }
    }
    return min_value;
}