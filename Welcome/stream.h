#ifndef STREAM_H
#define STREAM_H
#include <string>
using namespace std;


void test();

string promptUserForFile(ifstream & infile, string prompt);

int stringToInteger(string str);

int getIntegerv2(string prompt);

struct Point
{
public:
    int x;
    int y;
};

#endif // STREAM_H
