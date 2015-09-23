//
//  LeaveEvent.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "LeaveEvent.h"

string LeaveEvent::processEvent() {
    if (DEBUG_LEAVE_ACTION) { cout << "LeaveEvent - processEvent() called" << endl; }
    
    return mBar->leave(mTime, mGroupSize);
}

string LeaveEvent::toString() {
    string s = "LeaveEvent:\n";
    s += "\ttime: " + to_string(mTime) + "\n";
    s += "\tgroupSize: " + to_string(mGroupSize);
    return s;
}