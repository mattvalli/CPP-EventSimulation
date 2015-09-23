//
//  Bar.h
//  EventSimulation
//
//  Created by Matthew Valli on 23/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__Bar__
#define __EventSimulation__Bar__

#include <iostream>
#include <vector>
#include "event.h"
#include "EventSimulation.h"
#include "RandomInteger.h"
#include "Beer.h"
#include "Log.h"
#include "FileWriter.h"


class Bar {
private:
    // DEBUG
    static const bool DEBUG_ARRIVAL_GEN = false;
    
    // LOGS
    static const string LOG_PATH;
    static const string ARRIVAL_GEN_LOG;
    
    // FLAGS
    static const int FAULT_FLAG = -1;
    
    // CONSTANTS
        // Generic Constants
    static const unsigned int INITIAL_TIME = 0;
    static const unsigned int INITIAL_PROFIT = 0;
    static const unsigned int INITIAL_CUSTOMERS = 0;
        // Default Constants
    static const unsigned int DEFAULT_BAR_SIZE = 50;
    static const unsigned int DEFAULT_MINUTES_OF_OPERATION = 240;
    // CONSTANTS - APPLICATION
    // ArriveEvent Generation
    static const unsigned int MIN_ARRIVE_INTERVAL = 2;
    static const unsigned int MAX_ARRIVE_INTERVAL = 5;
    static const unsigned int MIN_PARTY_SIZE = 1;
    static const unsigned int MAX_PARTY_SIZE = 5;
    // ArriveEvent Generators
    static const unsigned int MIN_ORDER_INTERVAL = 2;
    static const unsigned int MAX_ORDER_INTERVAL = 10;
    
    // OrderEvent Generators
    static const unsigned int MIN_OCCUPY_INTERVAL = 30;
    static const unsigned int MAX_OCCUPY_INTERVAL = 60;
    static const unsigned int MIN_BEER = static_cast<int>(Beer::BEER_LOCAL);
    static const unsigned int MAX_BEER = static_cast<int>(Beer::BEER_SPECIALTY);
    
    
    
    // MEMBERS
        // Output Logs
        long mSimRunTime;
        FileWriter *mArrivalGenLog;
        // EventSimulation Object
        EventSimulation *mBarSim;
        
        // Bar Details
        string mBarName;
        unsigned int mMinutesOfOperation;
        unsigned int mCapacity;
        unsigned int mFreeChairs;
        // Tracking Details
        unsigned int mCustomersServiced;
        unsigned int mCustomersNotServiced;
        unsigned int mCurrentTime;
        double mProfit;
            // GroupSize
    unsigned int mGroupSize1;
    unsigned int mGroupSize2;
    unsigned int mGroupSize3;
    unsigned int mGroupSize4;
    unsigned int mGroupSize5;
    
        // Used to controll Randomly Generation values
        RandomInteger *mArriveInterval;
        RandomInteger *mPartySizeGen;
        RandomInteger *mOrderIntervalGen;
        RandomInteger *mOccupyIntervalGen;
        RandomInteger *mBeerTypeGen;
    
    
public:
    // ENUM
    enum SeatingStatus {
        CAPACITY_AVAILABLE,
        CAPACITY_EXCEEDED,
        OPERATION_CLOSED
    };
    
    // CONSTRUCTORS
    Bar();
    Bar(string barName, unsigned int capacity, unsigned int minutesOfOperation);
    
    // EVENT SIMULATION
    string run();
    string generateArrivals();
    SeatingStatus canSeat(unsigned int time, unsigned int numberOfPeople);
    string arrive(unsigned int time, unsigned int groupSize);
    string order(unsigned int time, unsigned int beerType);
    string leave(unsigned int time, unsigned int numberOfPeople);
    string simulationSummary();
    
    // CONVENIENCE METHODS
    void trackGroupSize(unsigned int groupSize);
    string groupDistributionSummary();
    Beer randomBeer();
    string beerTypeAsString(Beer beerType);
    double beerTypeAsDouble(Beer beerType);
    
    // ACCESSOR METHODS
    unsigned int getCurrentTime();
    void setCurrentTime(unsigned int t);
    unsigned int getProfit();
    void setProfit(int p);
    EventSimulation* getSimulator();
    void setSimRunTime(long time);
    
    // LOGS
    string logFilename(string logName);
    
    // Testing
    void testGen();
    
};

#endif /* defined(__EventSimulation__Bar__) */
