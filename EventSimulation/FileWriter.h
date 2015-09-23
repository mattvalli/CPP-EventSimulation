//
//  FileWriter.h
//  EventSimulation
//
//  Created by Matthew Valli on 8/03/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#ifndef __EventSimulation__FileWriter__
#define __EventSimulation__FileWriter__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileWriter {
private:
    // CONSTANTS
    const string DEFAULT_FILENAME = "defaultFileWriter.txt";
    // MEMBERS
    string mFileName;
    ofstream mFile;
    fstream mStream;
    
public:
    // CONSTRUCTORS
    FileWriter();
    FileWriter(string fileName);
    ~FileWriter();
    
    // CONVENIENCE METHODS
    void writeLine(string line, ios_base::openmode mode, bool addNewLine, bool outputToConsole);
    
    // Appending
    void append(string line, bool addNewLine, bool outputToConsole);
    void append(string line);
    
    // Overwrite
    void overwrite(string line, bool addNewLine, bool outputToConsole);
    void overwrite(string line);
    
    
};


#endif /* defined(__EventSimulation__FileWriter__) */
