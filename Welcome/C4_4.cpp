#include "stream.h"
#include "simpio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;





int main_C4_4(){
    return 0;
}

void copyStream(ifstream & infile, ofstream & outfile){
    while(true){
        int ch = infile.get();
        if (ch == EOF) break;
        outfile.put(ch);
    }
}

void copyStream_v2(ifstream & is, ofstream & os){
    char ch;
    while(is.get()){
        ch = is.get();
        os.put(ch);
    }
}
