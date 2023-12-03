#include "stream.h"
#include "simpio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*

int main(){
    //test();
    ifstream infile;

    promptUserForFile(infile,"Input file: ");

    //promptUserForFilename("test","Input file: ");
    char ch;
    while (infile.get(ch)){
        cout.put(ch);
    }
    infile.close();
    return 0;
}
*/
int main_readline(){
    string line;
    ifstream infile;
    promptUserForFile(infile,"Input file: ");
    while (getline(infile,line)){
        cout << line << endl;
    }
    return 0;
}


int sum_line();

int sum_line_v2();


int main_C4_3(){
    //sum_line();
    //sum_line_v2();
    //getIntegerv2("12");
    getInteger("12412");
    return 0;
}

// sum by lines
int sum_line() {
    ifstream infile;
    promptUserForFile(infile,"Input file: ");
    int total = 0;
    int value;
    while(infile >> value){
        total += value;
    }
    infile.close();
    cout << "The sum is " << total << endl;
    return 0;
}

//sum  by lines v2
int sum_line_v2() {
    ifstream infile;
    promptUserForFile(infile,"Input file: ");
    int total = 0;
    string line;
    while(getline(infile,line)){
        total += stringToInteger(line);
    }
    infile.close();
    cout << "The sum is " << total << endl;
    return 0;
}

