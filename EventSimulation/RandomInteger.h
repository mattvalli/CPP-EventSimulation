//
//  RandomInteger.h
//  EventSimulation
//
//  Created by Matthew Valli on 24/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__RandomInteger__
#define __EventSimulation__RandomInteger__

#include <iostream>
#include <random>
#include <vector>

using namespace std;

class RandomInteger {
private:
    unsigned int mLow;
    unsigned int mHigh;
public:
    // MEMBERS
    RandomInteger(int low, int high);
    ~RandomInteger();
    unsigned int nextRandom();
    unsigned int originalRandom(int low, int high);
    unsigned int randBetween(int low, int high);
    unsigned int uniformDistribution(int low, int high);
    unsigned int weightedDistribution(int low, int high, vector<int> distributions);
};

#endif /* defined(__EventSimulation__RandomInteger__) */
