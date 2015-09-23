//
//  ArriveEvent.h
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__ArriveEvent__
#define __EventSimulation__ArriveEvent__

#include <iostream>
#include "BarEvent.h"
#include "RandomInteger.h"

class ArriveEvent : public BarEvent {
protected:
    // DEBUG
    static const bool DEBUG_ARRIVE_ACTION = false;
    // MEMBERS
    RandomInteger *mTimeInterval;
public:
    // CONSTRUCTOR
    ArriveEvent (unsigned int time, unsigned int gs, Bar &b);
    // METHODS
    virtual string processEvent();
    // CONVENIENCE METHODS
    virtual string toString();
};

#endif /* defined(__EventSimulation__ArriveEvent__) */
