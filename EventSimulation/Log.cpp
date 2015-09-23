//
//  Log.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 9/03/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "Log.h"

using namespace std;


const string Log::APP_NAME = "BeerBarDrinkers";
const string Log::LOG_PATH = "/Users/Admin/Desktop/EventSimulationOutput/logs/";


Log::Log() {
    Log("/Users/Admin/Desktop/", "ProjectName","DefaultLog",".txt");
}

Log::Log(string rootFolder, string projectName, string logName, string extension) {
    
    // Initialize Members
    mRootFolder = rootFolder;
    mAppName = projectName;
    mExtension = extension;
    mCurrentRunTime = time(0);
    mLogInstance = new FileWriter(logFilename(logName));
    
    
}

string Log::logFilename(string subFolder, string logName, long time) {
    string logStr = mRootFolder + "/";
    logStr += subFolder + "/";
    logStr += mAppName + "_" + to_string(time) + "_" + logName;
    logStr += mExtension;
    
    //cout << logStr << endl;
    return logStr;
}

string Log::logFilename(string logName) {
    return logFilename("", logName, mCurrentRunTime);
}

void Log::setLogTime(long runtime) {
    mCurrentRunTime = runtime;
}