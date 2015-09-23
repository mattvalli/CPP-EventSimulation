//
//  main.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 23/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include <iostream>
#include "Bar.h"
#include "SimulationController.h"
#include "RandomInteger.h"
#include "BarEvent.h"
#include "ArriveEvent.h"
#include "OrderEvent.h"
#include "LeaveEvent.h"
#include "FileWriter.h"

const int LOCAL_BEER = 2;
const int IMPORT_BEER = 3;
const int SPECIALTY_BEER = 4;

using namespace std;

// SIGNATURES
void runSimulation();
void testFileWriter();
void testBarEvent(Bar &bar);
void testArriveEvent(Bar &bar);
void testOrderEvent(Bar &bar);
void testPolymorphisum(Bar &bar);
void testSimulation();



int main(int argc, const char * argv[]) {
    
    
    // Runs the simulation defined in the function
    runSimulation();
    
    
    /*
    // Create a Bar
    Bar *test = new Bar("test bar", 50, 240);
    
    // Set the RunTime for the Current Simulation
    test->setSimRunTime(time(0));
    test->generateArrivals();
    test->testGen();
     */
     
    return 0;
}


// SIMULATION
void runSimulation() {
    // Seed the random Generator
    srand((int)time(0));
    
    // Get RunTime
    long runTime = time(0);
    
    // Define Constant Values
    const unsigned int MINUTES_OF_OPERATION = 240;
    
    // Create the Bar
    Bar *bar50 = new Bar("SoftwareGurusBar[50]", 50, MINUTES_OF_OPERATION);
    bar50->setSimRunTime(runTime);
    
    // Run the Simulation
    bar50->run();
}

// TESTING
void testing(Bar &bar) {
    // POLYMORPHISUM
    testBarEvent(bar);
    testArriveEvent(bar);
    testOrderEvent(bar);
    testPolymorphisum(bar);
    testSimulation();
    
    // OUTPUT
    testFileWriter();
}
void testSimulation() {
    
    // Create a new simulation
    SimulationController *sim = new SimulationController("SimTest", 240);
    
    // Run Simulation
    sim->run();
    
}

void testFileWriter() {
    // Create a FileWriter
    FileWriter *mFile = new FileWriter("/Users/Admin/Desktop/testWriter.txt");
    
    // Create a test string
    string line = "This is a test!";
    
    // Write the line
    mFile->append(line, false, true);
    
    // Add more on the same line
    mFile->append(" Continuing with testcase...", true, true);
    
    // Add more lines
    mFile->append("Next Line");
    mFile->append("Hopefully this is working.");
    mFile->append("End the test");
    
}

// POLYMORPHISM - EVENT
void testPolymorphisum(Bar &bar) {
    Event *base = new Event();
    Event *barEvt = new BarEvent(1,2, bar);
    Event *arrive = new ArriveEvent(2,4, bar);
    Event *order = new OrderEvent(3,6, bar);
    Event *leave = new LeaveEvent(4,8, bar);
    
    base->processEvent();
    barEvt->processEvent();
    arrive->processEvent();
    order->processEvent();
    leave->processEvent();
    
}

void testBarEvent(Bar &bar) {
    // Create a BarGroup
    BarEvent *barEvent = new BarEvent(10, 5, bar);
    cout << barEvent->toString() << endl;
    
    barEvent->processEvent();
}

void testArriveEvent(Bar &bar) {
    // Create a BarGroup
    ArriveEvent *arriveEvent = new ArriveEvent(10, 7, bar);
    cout << arriveEvent->toString() << endl;
    
    arriveEvent->processEvent();
}

void testOrderEvent(Bar &bar) {
    // Create a BarGroup
    OrderEvent *orderEvent = new OrderEvent(15, 3, bar);
    cout << orderEvent->toString() << endl;
    
    orderEvent->processEvent();
}

void testRandomInteger() {
    // Test Randomized
    RandomInteger *beerGenerator = new RandomInteger(LOCAL_BEER,SPECIALTY_BEER);
    
    for (int i = 0; i < 100; i++) {
        
        // Create a random number between 2 and 4
        int randomBeer = beerGenerator->nextRandom();
        
        // Switch to print beer
        //cout << "BeerType: " << randomBeer << endl;
        
        cout << "ORDER:" << endl;
        switch (randomBeer) {
            case LOCAL_BEER:
                cout << "Local Beer" << endl;
                break;
            case IMPORT_BEER:
                cout << "Import Beer" << endl;
                break;
            case SPECIALTY_BEER:
                cout << "Specialty Beer" << endl;
                break;
                
            default:
                break;
        }
    }
}
