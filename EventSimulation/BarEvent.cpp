//
//  BarEvent.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "BarEvent.h"
#include <string>

using namespace std;

BarEvent::BarEvent(unsigned int time, unsigned int gs, Bar& b) : Event(time) {
    // MEMBERS
    mGroupSize = gs;
    mBar = &b;
};

string BarEvent::toString() {
    string s = "BarEvent\n";
    // Append the GroupSize
    s += "time: " + to_string(mTime);
    s += "groupSize: " + to_string(mGroupSize);

    return s;
}

string BarEvent::processEvent() {
    return "BarEvent - processEvent() called";
}
