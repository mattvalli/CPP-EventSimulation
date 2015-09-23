//
//  SimulationController.h
//  EventSimulation
//
//  Created by Matthew Valli on 25/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__SimulationController__
#define __EventSimulation__SimulationController__

#include <iostream>
#include "EventSimulation.h"
#include "Bar.h"


class SimulationController {
private:
    // CONSTANTS
    const unsigned int MINUTES_OF_OPERATION = 240;
    
    // MEMBERS
    EventSimulation* mEventSimulator;
    Bar mBar;  // The Theoretical Bar being simulated
    unsigned int mSimPeriod;

        
public:
    // CONSTRUCTORS
    SimulationController();
    SimulationController(string simName, unsigned int simPeriod); // Time allotted to run Simulation
    
    // SIMULATION
    void run();
    
    // CONVENIENCE METHODS
    virtual string toString();
    virtual string simulationSummary();
    
    
    
    
    
    
};

#endif /* defined(__EventSimulation__SimulationController__) */
