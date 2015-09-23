//
//  Bar.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 23/02/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "Bar.h"
#include "ArriveEvent.h"
#include "OrderEvent.h"
#include "LeaveEvent.h"


using namespace std;

// CONSTANTS
const string Bar::ARRIVAL_GEN_LOG = "arrivalGenerationLog";

// CONSTRUCTORS
/* DEFAULT CONSTRUCTOR
 * Assumes 50 chairs in the Bar (DEFAULT_BAR_SIZE)
 * Initializes the Profit to 0 (INITIAL_PROFIT)
 */
Bar::Bar() {
   Bar("DEFAULT BAR", DEFAULT_BAR_SIZE, DEFAULT_MINUTES_OF_OPERATION);
}

Bar::Bar(string barName, unsigned int capacity, unsigned int minutesOfOperation) {
    
    // Initialize mSimRunTime to FAULT_FLAG
    mSimRunTime = FAULT_FLAG;
    
    // Create EventSimulation Object
    mBarSim = new EventSimulation(barName, minutesOfOperation);
    
    // Initialize Values
    mBarName = barName;
    mMinutesOfOperation = minutesOfOperation;
    mCapacity = capacity;
    mFreeChairs = capacity;
    mProfit = INITIAL_PROFIT;
    mCustomersServiced = INITIAL_CUSTOMERS;
    mCustomersNotServiced = INITIAL_CUSTOMERS;
    
    // Random Value generators
    mArriveInterval = new RandomInteger(MIN_ARRIVE_INTERVAL, MAX_ARRIVE_INTERVAL);
    mPartySizeGen = new RandomInteger(MIN_PARTY_SIZE, MAX_PARTY_SIZE);
    mOrderIntervalGen = new RandomInteger(MIN_ORDER_INTERVAL, MAX_ORDER_INTERVAL);
    mOccupyIntervalGen = new RandomInteger(MIN_OCCUPY_INTERVAL, MAX_OCCUPY_INTERVAL);
    mBeerTypeGen = new RandomInteger(MIN_BEER, MAX_BEER);
    
    // TRACKING
        // GROUP SIZE
        mGroupSize1 = INITIAL_CUSTOMERS;
        mGroupSize2 = INITIAL_CUSTOMERS;
        mGroupSize3 = INITIAL_CUSTOMERS;
        mGroupSize4 = INITIAL_CUSTOMERS;
        mGroupSize5 = INITIAL_CUSTOMERS;
}


// EVENT SIMULATION
string Bar::run() {
    
    if (VERBOSE_STAGE) { cout << "Generating Arrivals..." << endl; }
    // Set the SimRunTime for the Current Run (Value changes every run)
    mSimRunTime = time(0);
    
    // Output String
    string output = "SIMULATION APPLICATION - BEER, BAR, DRINKERS\n";
    
    // Initialize Logs
    mArrivalGenLog = new FileWriter(logFilename(ARRIVAL_GEN_LOG));
    
    // Generate Theoretic Party Arrivals
    output += generateArrivals();
    
    // Run Simulation
    output += mBarSim->run();
    
    // Construct Simulation Report
    output += simulationSummary();
    
    // Write to Log
    mArrivalGenLog->append(output, true, true);
    
    return output;
}
string Bar::generateArrivals() {
    
    // Log File Headers
    string arrivalGenLogStr;
    string arrivalHeader = "GENERATING ARRIVALS\n";
    arrivalHeader += "\tMinutes Ellapsed\t|\tArrival Time\t|\tParty Size\n";
    arrivalHeader += "________________________________________________________________";
    arrivalHeader += "\n";
    
    unsigned int time = 0;
    // Run simulation while the mCurrentTime is less then the mSimulationPeriod
    while (time < mMinutesOfOperation) {
        
        // Generate a groupSize
        unsigned int groupSize = mPartySizeGen->nextRandom();
        // Generate interval between previous guest arrived
        unsigned int minutesToMove = mArriveInterval->nextRandom();
       
        // Update the mCurrentTime of the Simulation
        time += minutesToMove;
        
        arrivalGenLogStr += "\t\t\t" + to_string(minutesToMove) + "\t\t\t|\t\t" + to_string(time) + "\t\t\t|\t\t" + to_string(groupSize);
        arrivalGenLogStr += "\n";
        //mArrivalGenLog->append(arrivalGenLogStr, true, true);
        
        // Create a new ArrivalEvent
        ArriveEvent *e = new ArriveEvent(time, groupSize, *this);
        
        // Add the Event to the Simulation PriorityQueue
        mBarSim->scheduleEvent(*e);
        
    }
    return arrivalHeader + arrivalGenLogStr;
}

void Bar::testGen() {
    mBarSim->emptyEvents();
}


// CONENIENCE METHODS
Bar::SeatingStatus Bar::canSeat (unsigned int time, unsigned int numberOfPeople) {
    // If the Current Time is passed the MinutesOfOperation, the bar is closed
    if (time > mMinutesOfOperation) {
        mCustomersNotServiced += numberOfPeople;
        return SeatingStatus::OPERATION_CLOSED;
    }
    // if sufficient room, then seat customers
    if (numberOfPeople < mFreeChairs) {
        mFreeChairs -= numberOfPeople;
        return SeatingStatus::CAPACITY_AVAILABLE;
    } else {
        mCustomersNotServiced += numberOfPeople;
        return SeatingStatus::CAPACITY_EXCEEDED;
    }
}

string Bar::arrive(unsigned int time, unsigned int groupSize) {
    // Serve beer
    string output = "Time: " + to_string(time) + " - ";
    //cout << " serviced order for " << beerType << endl;
    
    output += "GROUP ARRIVES (size: " + to_string(groupSize) + ") ";
    
    SeatingStatus currentStatus;
    
    if (( currentStatus = canSeat(time, groupSize)) == SeatingStatus::CAPACITY_AVAILABLE) {
        // Generate New Order Time
        int orderTime = time + mOrderIntervalGen->nextRandom();
        // place an order within 2 & 10 minutes
        getSimulator()->scheduleEvent ( *new OrderEvent(orderTime, groupSize, *this) );
        
        // Track Party Size
        trackGroupSize(groupSize);
    }
    
    // Generate Message
    switch (currentStatus) {
        case SeatingStatus::CAPACITY_AVAILABLE:
            output += " Group is seated\n";
            break;
        case SeatingStatus::CAPACITY_EXCEEDED:
            output += " No room, group leaves\n";
            break;
        case SeatingStatus::OPERATION_CLOSED:
            output += " BAR CLOSED - Not receiving new customers\n";
            
        default:
            break;
    }
    
    return output;
}

string Bar::order(unsigned int time, unsigned int groupSize) {
    // Serve beer
    string output = "Time: " + to_string(time) + " - ";
    //cout << " serviced order for " << beerType << endl;
    
    output += "GROUP ORDERS (size: " + to_string(groupSize) + ")\n";
    
    // Create a variable for storing the Order Total Value
    int totalValue = 0;
    
    string order = "";
    
    // Table is ready to order, Order Beer for each person
    for (int i = 0; i < groupSize; i++) {
        // Generate a Beer
            Beer beer = randomBeer();
        
        // Output to Console
        order += "\tPerson " + to_string(i + 1) + " ordered " + beerTypeAsString(beer) + "\n";
        
        // Update the Total Value for the order
        totalValue += beerTypeAsDouble(beer);
    }
    
    // Output the orderTotal
    order += "\tORDER TOTAL: $" + to_string(totalValue) + "\n";
    //cout << order;
    
    // Update the Total Profit
    mProfit += totalValue;
    
    // Span/Create a LeaveEvent
    mBarSim->scheduleEvent( *new LeaveEvent(time + mOccupyIntervalGen->nextRandom(), groupSize, *this));
    
    return output;
}

string Bar::leave(unsigned int time, unsigned int numberOfPeople) {
    // People leave
    string output = "Time: " + to_string(time) + " - ";
    output += "GROUP LEAVES (size: " + to_string(numberOfPeople) + ")\n";
    
    // Free chairs
    mFreeChairs += numberOfPeople;
    mCustomersServiced += numberOfPeople;
    mCurrentTime = time;
    
    return output;
}

string Bar::simulationSummary() {
    // Temporarily change float percision
    //cout.setf(ios::fixed, ios::floatfield); // set fixed floating format
    //cout.precision(2); // for fixed format, two decimal places
    
    //
    string s = "BAR REPORT\n";
    s += "Seats: " + to_string(mFreeChairs) + "\n";
    s += "Customers Remaining: " + to_string(mCapacity - mFreeChairs) + "\n";
    s += "Customers Serviced: " + to_string(mCustomersServiced) + "\n";
    s += "Customers Not Serviced: " + to_string(mCustomersNotServiced) + "\n";
    s += "Minutes Passed Close: " + to_string((mCurrentTime - mMinutesOfOperation)) + "\n";
    s += "TOTAL PROFIT: " + to_string(mProfit) + "\n";
    
    s += + "\n" + groupDistributionSummary();
    
    return s;
}

string Bar::groupDistributionSummary() {
    string s = "GROUP DISTRIBUTION SUMMARY\n";
    s += "Group Size \tNumber of Groups\n";
    s += "\t1\t\t" + to_string(mGroupSize1) + "\n";
    s += "\t2\t\t" + to_string(mGroupSize2) + "\n";
    s += "\t3\t\t" + to_string(mGroupSize3) + "\n";
    s += "\t4\t\t" + to_string(mGroupSize4) + "\n";
    s += "\t5\t\t" + to_string(mGroupSize5) + "\n";
    
    return s;
}


// CONVENIENCE METHODS
void Bar::trackGroupSize(unsigned int groupSize) {
    switch (groupSize) {
        case 1:
            mGroupSize1++;
            break;
        case 2:
            mGroupSize2++;
            break;
        case 3:
            mGroupSize3++;
            break;
        case 4:
            mGroupSize4++;
            break;
        case 5:
            mGroupSize5++;
            break;
            
        default:
            break;
    }
}

Beer Bar::randomBeer() {
    return static_cast<Beer>( mBeerTypeGen->nextRandom() );
}

string Bar::beerTypeAsString(Beer beerType) {
    string beer = "";
    switch (beerType) {
        case Beer::BEER_LOCAL:
            beer = "Local Beer";
            break;
        case Beer::BEER_IMPORT:
            beer = "Import Beer";
            break;
        case Beer::BEER_SPECIALTY:
            beer = "Specialty Beer";
            break;
            
        default:
            beer = "Not an implemented BeerType";
            break;
    }
    return beer;
}

double Bar::beerTypeAsDouble(Beer beerType) {
    return (double) beerType;
}

// ACCESSOR METHODS
unsigned int Bar::getCurrentTime() {
    return mCurrentTime;
}
void Bar::setCurrentTime(unsigned int t) {
    mCurrentTime = t;
}
unsigned int Bar::getProfit() {
    return mProfit;
}
void Bar::setProfit(int p) {
    mProfit = p;
}

EventSimulation* Bar::getSimulator() {
    return mBarSim;
}

void Bar::setSimRunTime(long time) {
    mSimRunTime = time;
}

string Bar::logFilename(string logName) {
    string logStr = Log::LOG_PATH + Log::APP_NAME +  to_string(mSimRunTime) + "_" + logName;
    logStr +=  mBarName + ".txt";
    
    //cout << logStr << endl;
    return logStr;
}