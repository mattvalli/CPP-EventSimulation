//
//  Event.h
//  EventSimulation
//
//  Created by Matthew Valli on 23/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__Event__
#define __EventSimulation__Event__

#include <iostream>
#include "Comparable.h"


class Event : public Comparable {
    public:
        // MEMBERS
        unsigned int mTime;

        // METHODS
    Event();
    Event (unsigned int t): mTime(t) {}
    
    // Accessor Methods
    int getTime();
    
    // Polymorphism
    virtual string processEvent();
    virtual int compareTo(Comparable& obj);
    virtual string toString();
};

#endif /* defined(__EventSimulation__Event__) */
