#include "Util.h"
//global variables
ifstream fin;
ofstream fout;

// global functions
void globalInit(){
    fin.open("input.txt");
    fout.open("output.txt");
}