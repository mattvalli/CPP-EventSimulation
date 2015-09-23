//
//  LeaveEvent.h
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__LeaveEvent__
#define __EventSimulation__LeaveEvent__

#include <iostream>
#include "BarEvent.h"

using namespace std;

class LeaveEvent : public BarEvent {
private:
    // DEBUG
    static const bool DEBUG_LEAVE_ACTION = false;
    
    
public:
    // CONSTRUCTORS
    LeaveEvent (unsigned int time, unsigned int gs, Bar &bar)
    : BarEvent(time, gs, bar) {}
    // VIRTUAL METHODS
    virtual string processEvent ();
    // CONVENIENCE METHODS
    virtual string toString();
    
};

#endif /* defined(__EventSimulation__LeaveEvent__) */
