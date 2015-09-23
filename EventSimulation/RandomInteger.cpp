//
//  RandomInteger.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "RandomInteger.h"

using namespace std;

// CONSTRUCTOR
RandomInteger::RandomInteger(int low, int high) {
    //
    mLow = low;
    mHigh = high;
}

// DESTRUCTOR
RandomInteger::~RandomInteger() {}

// CONVENIENCE METHODS
unsigned int RandomInteger::nextRandom() {
    return originalRandom(mLow, mHigh);
}
unsigned int RandomInteger::randBetween(int low, int high) {
    return uniformDistribution(low, high);
}

unsigned int RandomInteger::originalRandom(int low, int high) {
    // Calculate the max
    int max = high - low + 1;
    // Get a random value
    unsigned int rval = rand();
    // Reduce the random value within the max
    rval = rval % max;
    return low + rval;
}

unsigned int RandomInteger::uniformDistribution(int low, int high) {
    
    int i;
    i = (rand()%high)+1;
    
    return i;
}

unsigned int RandomInteger::weightedDistribution(int low, int high, vector<int> distributions) {
    unsigned int r = 0;
    
    
    
    return r;
}