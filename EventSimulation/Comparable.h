//
//  Comparable.h
//  EventSimulation
//
//  Created by Matthew Valli on 25/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__Comparable__
#define __EventSimulation__Comparable__

#include <iostream>

using namespace std;

class Comparable {
public:
    Comparable() {}
    virtual ~Comparable() {}
    virtual int compareTo(Comparable &obj) = 0;
    virtual string toString() { return "Comparable Object"; }
    enum CompareType {
        LESS_THAN = -1,
        EQUAL = 0,
        GREATER_THAN = 1
    };
};

#endif /* defined(__EventSimulation__Comparable__) */
