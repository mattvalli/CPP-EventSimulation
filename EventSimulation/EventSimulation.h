//
//  EventSimulation.h
//  EventSimulation
//
//  Created by Matthew Valli on 28/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__EventSimulation__
#define __EventSimulation__EventSimulation__

#include <iostream>
#include "PriorityQueue.cpp"
#include "Event.h"

using namespace std;

// OUTPUT FLAGS
const bool VERBOSE = false;
const bool VERBOSE_STAGE = false;
// DEBUG FLAGS
const bool DEBUG_PRIORITY_QUEUE = false;

class EventSimulation {
private:
    // CONSTANTS
    const unsigned int INITIAL_TIME = 0;

    // MEMBERS
    // Data Structure
    PriorityQueue *mSimulationEvents;
    
    // Sim Details
    string mSimulationName;
    unsigned int mSimulationPeriod;
    
    // Progressive Tracking Vars
    unsigned int mCurrentTime;
    unsigned int mExecutedEvents;
    
public:
    // CONSTRUCTORS
    EventSimulation(string simName, unsigned int simPeriod);
    
    // SIMULATION
    string run();
    void scheduleEvent(Event& e);
    string simEventAction();
    string outputSimulation();
    
    // CONVENIENCE METHODS
    string toString();
    string simulationSummary();
    
    // TESTING
    void emptyEvents();
};

#endif /* defined(__EventSimulation__EventSimulation__) */
