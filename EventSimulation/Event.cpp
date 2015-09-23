//
//  Event.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 23/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

// DEBUG
const bool DEBUG_COMPARE = false;

#include "Event.h"

using namespace std;

Event::Event() {
    mTime = 0;
}

string Event::processEvent() {
    return "Event - processEvent() called";
}

int Event::compareTo(Comparable& obj) {
    // Min-Heap - time of currentObject is less than e.mTime
    Event e = dynamic_cast<Event&>(obj);
    int result = CompareType::EQUAL;
    
    // The time is Smaller
    if (mTime < e.mTime) result = CompareType::LESS_THAN;
    // The time is Larger
    if (mTime > e.mTime) result = CompareType::GREATER_THAN;
    
    if (DEBUG_COMPARE) cout << "Comparing - this.mTime: " + to_string(mTime) + " - obj.mTime: " + to_string(e.mTime) << " - RETURN RESULT: " << to_string(result) << endl;
    
    return result;
}

string Event::toString() {
    string s = "EVENT\n";
    s += "time: " + to_string(mTime) + "\n";
    
    return s;
}

// ACCESSOR METHODS
int Event::getTime() {
    return mTime;
}