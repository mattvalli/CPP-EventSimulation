//
//  OrderEvent.h
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__OrderEvent__
#define __EventSimulation__OrderEvent__

#include <iostream>
#include "BarEvent.h"
#include "Beer.h"
#include "RandomInteger.h"

using namespace std;

class OrderEvent : public BarEvent {
private:
    // DEBUG
    const bool DEBUG_ORDER_ACTION = false;
    // CONSTANTS
    const unsigned int MIN_BEER = static_cast<int>(Beer::BEER_LOCAL);
    const unsigned int MAX_BEER = static_cast<int>(Beer::BEER_SPECIALTY);
    RandomInteger *mOccupyInterval;
    RandomInteger *mBeerGen;

public:
    // CONSTRUCTORS
    OrderEvent (unsigned int time, unsigned int gs, Bar &bar);
    // VIRTUAL METHODS
    virtual string processEvent ();
    // CONVENIENCE METHODS
    virtual string toString();
    string beerTypeAsString(int beerType);
    
};

#endif /* defined(__EventSimulation__OrderEvent__) */
