#include "point.h"
#include "direction.h"
using namespace std;


int main_Point(){
    Point x1;
    x1.x = 1;
    x1.y = 2;

    Point x2;
    x2.x = 1;
    x2.y = 2;

    operator==(x1,x2);
    cout << x1 << x2 << endl;
    cout << operator==(x1,x2) << endl;

    Point x3;
    x3.x = 2;
    x3.y = 2;
    operator!=(x1,x2);
    cout << x1 << x2 << endl;
    cout << operator!=(x1,x2) << endl;

    if (x1 == x2){
        cout << 1;
        }else{
        cout << 0;
    }



    return 0;
}

int main_direction(){
    for (Direction dir = NORTH; dir <= WEST; dir++){
        cout << dir << endl;
    }
    return 0;
}
