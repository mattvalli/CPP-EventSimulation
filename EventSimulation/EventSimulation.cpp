//
//  EventSimulation.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 28/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "EventSimulation.h"

using namespace std;

// CONSTRUCTORS
EventSimulation::EventSimulation(string simName, unsigned int simPeriod) {
    
    // MEMBERS
    // Data Structure Initialization
    mSimulationEvents = new PriorityQueue();
    
    // Sim Details
    mSimulationName = simName;
    mSimulationPeriod = simPeriod;
    
    // Progressive Tracking Vars
    mCurrentTime = INITIAL_TIME;
    mExecutedEvents = 0;
    
}



// SIMULATION METHODS
string EventSimulation::run() {
    
    
    if (VERBOSE_STAGE) {
        if (mSimulationEvents->empty()) { cout << "Failed to generate arrivals!" << endl; }
        else { cout << "Arrivals Generated: " << mSimulationEvents->size() << endl; }
        
        cout << "Running Simulation..." << endl;
    }
    
    // Construct String of Simulation Settings
    string simSetting = "SIMULATION SETTINGS\n";
    simSetting += toString();
    
    // TESTING - Output the priority queue
    if (DEBUG_PRIORITY_QUEUE) { cout << mSimulationEvents->toString(); }
    
    // Output Events when Removed from the Priority Queue
    string simOutput = outputSimulation();
    
    // Build a Full Report from the Sim Settings & Output
    string simReport = simSetting + "\n" + simOutput;
    
    return simReport;
}

void EventSimulation::scheduleEvent(Event& e) {
    // Insert the Event into the PriorityQueue of Events
    mSimulationEvents->insert(e);
}

void EventSimulation::emptyEvents() {
    while ( ! mSimulationEvents->empty() ) {
        cout << mSimulationEvents->remove()->toString() << endl;
    }
}


string EventSimulation::outputSimulation() {
    // String
    string output = "SIMULATION PROCESSING\n";
    
    // vvvvv DEBUG vvvvv
    //for (int i = 1; i < 5; i++) {
    // vvvvv NON-DEBUG vvvvv
    while (!mSimulationEvents->empty()) {
        output += simEventAction();
        
        // Increment mExecuted events
        mExecutedEvents++;
    }
    
    // Output Summary
    output += "\n";
    output += simulationSummary() + "\n";
    
    return output;
}

string EventSimulation::simEventAction() {
    if (VERBOSE) { cout << "Removing element from mSimulationEvents" << endl; }
    
    // String of Output
    string output;
    
    // Remove element from Priority Queue
    Event *e = dynamic_cast<Event*>(mSimulationEvents->remove());
    
    // Update the mCurrentTime
    mCurrentTime = e->mTime;
    
    // Process Event
    output += e->processEvent();
    
    // Build String
    output += e->toString() + "\n";
    
    // Clean up memory
    delete e;
    
    // Report Heap Activity
    output += "Elements Remaining in Min Heap: " + to_string(mSimulationEvents->size()) + "\n";
    
    // Log
    if (VERBOSE) {
        cout << output;
    }
    
    return output;
}


// CONVENIENCE METHODS
string EventSimulation::toString() {
    string s = "EVENT SIMULATION\n";
    s += "Name: " + mSimulationName + "\n";
    s += "Period: " + to_string(mSimulationPeriod) + "\n";
    
    return s;
}

string EventSimulation::simulationSummary() {
    string s = "SIMULATION REPORT\n";
    s += "Total Time: " + to_string(mSimulationPeriod) + "\n";
    s += "Total Events: " + to_string(mExecutedEvents) + "\n";
    return s;
}