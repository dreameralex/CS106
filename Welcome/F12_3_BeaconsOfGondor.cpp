#include <iostream>
#include <string>
using namespace std;

struct Tower {
    string name;
    Tower *link;
};

Tower *createBeaconsOfGondor();
Tower *createTower(string name, Tower *link);
void signal(Tower *start);
void freeList(Tower *list);

int main_F12_3(){
    Tower *list = createBeaconsOfGondor();
    signal(list);

    freeList(list);
    //signal(list);
    return 0;
}

Tower *createBeaconsOfGondor() {
    Tower *tp = createTower("Rohan", NULL);
    tp = createTower("Halifirien",tp);
    tp = createTower("Amo Din",tp);
    return createTower("Minas Tirith",tp);
}

Tower *createTower(string name, Tower *link){
    Tower *tp = new Tower;
    tp->name = name;
    tp->link = link;
    return tp;
}

void signal(Tower *start){
    for (Tower *tp = start; tp != NULL; tp = tp->link){
        cout << "Lighting " << tp->name << endl;
    }
}

void freeList(Tower *list) {
    if (list != NULL) {
        freeList(list->link);
        delete list;
    }
}
