//
//  Log.h
//  EventSimulation
//
//  Created by Matthew Valli on 9/03/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__Log__
#define __EventSimulation__Log__

#include <iostream>
#include "FileWriter.h"

using namespace std;

class Log {
private:
    // MEMBERS
    string mRootFolder;
    string mAppName;
    string mExtension;
    long mCurrentRunTime;
    FileWriter *mLogInstance;
    
public:
    // CONSTANTS
    static const string APP_NAME;
    static const string LOG_PATH;
    
    // CONSTRUCTORS
    Log();
    Log(string rootFolder, string projectName, string logName, string extension);
    
    // CONVENIENCE METHODS
    string logFilename(string subFolder, string logName, long time);
    string logFilename(string logName);
    
    // ACCESSOR METHODS
    void setLogTime(long time);
    
};

#endif /* defined(__EventSimulation__Log__) */
