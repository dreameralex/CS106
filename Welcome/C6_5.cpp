#include <iostream>
#include <iomanip>
#include "queue.h"
#include "random.h"
using namespace std;

const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 5;
const int SIMULATION_TIME = 2000;

class CheckoutLineSimulation{
public:
    void runSimulation(){

    }

    void printReport(){

    }

private:
    int nServed;
    int totalWait;
    int totalLength;

};

int main_class(){
    CheckoutLineSimulation  simulation;
    simulation.runSimulation();
    simulation.printReport();
    return 0;
}
