//
//  ArriveEvent.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include <iostream>
#include "ArriveEvent.h"
#include "OrderEvent.h"
#include "RandomInteger.h"


using namespace std;

ArriveEvent::ArriveEvent (unsigned int time, unsigned int gs, Bar &b)
: BarEvent(time, gs, b) {
    mTimeInterval = new RandomInteger(2, 10);
}

string ArriveEvent::processEvent() {
    if (DEBUG_ARRIVE_ACTION) { cout << "ArriveEvent - processEvent() called" << endl; }
    
    return mBar->arrive(mTime, mGroupSize);
}

string ArriveEvent::toString() {
    string s = "ArriveEvent:\n";
    s += "\ttime: " + to_string(mTime) + "\n";
    s += "\tgroupSize: " + to_string(mGroupSize);
    return s;
}