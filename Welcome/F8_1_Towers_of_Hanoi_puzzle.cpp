#include <iostream>
#include <simpio.h>
#include "set.h"
#include <random>
#include "random.h"
#include "gwindow.h"
#include <cmath>
using namespace std;

void moveTower(int n, char start, char finish, char tmp);

void moveSingleDisk(char start, char finish);

int main_move_tower(){
    int n = getInteger("Enter number of disks: ");
    moveTower(n, 'A', 'B', 'C');
    return 0;

}

void moveTower(int n, char start, char finish, char tmp){
    if (n==1){
        moveSingleDisk(start, finish);
    }else{
        moveTower(n-1, start, tmp, finish);
        moveSingleDisk(start, finish);
        moveTower(n-1, tmp, finish, start);
    }
}

void moveSingleDisk(char start, char finish){
    cout << start << " -> " << finish << endl;
}

bool subsetSumExists(Set<int> &set, int target);

uniform_int_distribution<unsigned> u(0,1000);
default_random_engine e;    // 生成无符号随机整数
int num = 0;
int main_subsetSumExists(){
    Set<int> set;
    for(int i = 0; i < 30; i++){
        //set.add(u(e));
        set.add(i);
    }
    cout << set;

    int temp = subsetSumExists(set, 6);
    cout << "\nnum: " << num << endl;

    /*

    if (temp){
        cout << "\nTrue";
    }else{
        cout << "\nFalse!";
    }
    cout << "\nnum: " << num;*/
    return 0;
}


bool subsetSumExists(Set<int> &set, int target){
    if(set.isEmpty()){
        return target == 0;
    }else{
        int element = set.first();
        Set<int> rest = set - element;
        num ++;
        return subsetSumExists(rest, target) || subsetSumExists(rest, target - element);

    }

}


Set<string> generatePermutations(string str);
int main_generatePermutations(){
    Set<string> set;
    set = generatePermutations("abcdefg");
    cout << endl << set;
    return 0;
}



Set<string> generatePermutations(string str){
    Set <string> result;
    if(str == ""){
        result += "";
    }else{
        for (int i = 0; i < str.length(); i++){
            char ch = str[i];
            // exclude str[i]
            string rest = str.substr(0,i) + str.substr(i+1);
            for (std:: string s: generatePermutations(rest)){
                result += ch + s;
            }
        }
    }

    return result;
}


//Figure 8-4
const double MIN_AREA = 10000;
const double MIN_EDGE = 20;
void subdivideCanvas(GWindow & gw, double x, double y, double width, double height);

int main_subdivideCanvas(){
    GWindow gw;
    gw.setWindowTitle("ALEX");
    gw.setColor("gray");
    cout<< "start" << endl;

    subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
    cout<< "end" << endl;
    return 0;
}


void subdivideCanvas(GWindow & gw, double x, double y, double width, double height){
    if (width * height >= MIN_AREA){
        if (width > height){
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            subdivideCanvas(gw, x, y, mid, height);
            subdivideCanvas(gw, x + mid, y, width - mid, height);
            gw.drawLine(x + mid, y, x + mid, y + height);
        }else{
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            subdivideCanvas(gw, x, y, mid, height);
            subdivideCanvas(gw, x, y + mid, width, height - mid);
            gw.drawLine(x, y + mid, x + width, y + mid);
        }
    }
}

// Figure 8-5
const double SIZE = 200;
const int ORDER = 4;

GPoint drawFractalLine(GWindow & gw, GPoint pt, double r, double theta, int order);

int main_drawFractalLine(){
    GWindow gw;
    cout << "Program to draw a snowflake fractal," << endl;
    double cx = gw.getWidth()/2;
    double cy = gw.getHeight()/2;
    gw.setColor("blue");
    GPoint pt(cx - SIZE/2, cy - sqrt(3.0) * SIZE / 6);
    pt = drawFractalLine(gw, pt, SIZE, 0, ORDER);
    pt = drawFractalLine(gw, pt, SIZE, -120, ORDER);
    pt = drawFractalLine(gw, pt, SIZE, 120, ORDER);

    return 0;
}


GPoint drawFractalLine(GWindow & gw, GPoint pt, double r, double theta, int order){
    if (order == 0){
        return gw.drawPolarLine(pt, r, theta);
    }else{
        pt = drawFractalLine(gw, pt, r / 3, theta, order - 1);
        pt = drawFractalLine(gw, pt, r / 3, theta + 60, order - 1);
        pt = drawFractalLine(gw, pt, r / 3, theta - 60, order - 1);
        return drawFractalLine(gw, pt, r / 3, theta, order - 1);
    }
}





