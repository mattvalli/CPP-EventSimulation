//
//  SimulationController.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 25/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "SimulationController.h"
#include "RandomInteger.h"
#include "ArriveEvent.h"


// CONSTRUCTORS
SimulationController::SimulationController() {
    SimulationController("Default Simulation", MINUTES_OF_OPERATION);
}

SimulationController::SimulationController(string simName, unsigned int simPeriod) {
    // Data Structure Initialization
    mEventSimulator = new EventSimulation(simName, simPeriod);
    
    // Members
    mSimPeriod = simPeriod;

}

// SIMULATION
void SimulationController::run() {
    
    // Run Simulation
    mEventSimulator->run();
    
}

// CONVENIENCE METHODS
string SimulationController::toString() {
    string s = "SIMULATION CONTROLLER\n";
    
    return s;
}

string SimulationController::simulationSummary() {
    string s = mEventSimulator->simulationSummary();
    s += "\n";
    s += mBar.simulationSummary();
    return s;
}