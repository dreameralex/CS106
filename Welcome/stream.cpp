#include "stream.h"
#include <iostream>
#include <fstream>
#include "error.h"
#include <sstream>
using namespace std;



void test(){
    cout<< "test";
}

string promptUserForFile(ifstream & infile, string prompt){
    while(true){
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if(!infile.fail()) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if (prompt == "") prompt = "Input file: ";
    }
}


int stringToInteger(string str) {
    istringstream stream(str);
    int value;
    stream >> value >> ws;
    if (stream.fail() || !stream.eof()) {
        error("stringToInteger: Illegal integer format");
    }
    return value;
}

int getIntegerv2(string prompt){
    int value;
    string line;
    while(true){
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value >> ws;
        if (!stream.fail() && stream.eof()) break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value;
}


