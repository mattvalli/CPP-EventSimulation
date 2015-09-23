//
//  BarEvent.h
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__BarEvent__
#define __EventSimulation__BarEvent__

#include <iostream>
#include <string>
#include "Event.h"
#include "Bar.h"

using namespace std;

class BarEvent : public Event {
public:
    // MEMBERS
    int mGroupSize;
    Bar *mBar;
    
    // CONSTRUCTORS
    BarEvent(unsigned int time, unsigned int gs, Bar& b);
    //
    virtual string processEvent();
    // CONVENIENCE METHODS
    string toString();
};


#endif /* defined(__EventSimulation__BarEvent__) */
