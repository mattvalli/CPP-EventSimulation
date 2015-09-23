//
//  OrderEvent.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "OrderEvent.h"
#include "LeaveEvent.h"

using namespace std;


OrderEvent::OrderEvent (unsigned int time, unsigned int gs, Bar &bar)
: BarEvent(time, gs, bar) {
    
}
string OrderEvent::processEvent() {
    if (DEBUG_ORDER_ACTION) { cout << "OrderEvent - processEvent() called" << endl; }
    
    
    // Call the Order Method
    return mBar->order(mTime, mGroupSize);
}


// CONVENIENCE METHODS
string OrderEvent::toString() {
    string s = "OrderEvent:\n";
    s += "\ttime: " + to_string(mTime) + "\n";
    s += "\tgroupSize: " + to_string(mGroupSize);
    return s;
}

