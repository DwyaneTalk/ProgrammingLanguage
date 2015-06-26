#include "Util.h"
//global variables
ifstream fin;
ofstream fout;

// global functions
void globalInit() {
    fin.open("input.txt");
    fout.open("output.txt");
}

void* renew(void* base, int count, int inc, int size) {
    void* new_base;
    if (new_base = new UInt8[(count + inc) * size]) {
        memcpy(new_base, base, count * size);
        return new_base;
    } else {
        cout << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
        exit(OVER);
    }
}