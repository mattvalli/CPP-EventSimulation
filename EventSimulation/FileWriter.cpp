//
//  FileWriter.cpp
//  EventSimulation
//
//  Created by Matthew Valli on 8/03/2015.
//  Copyright (c) 2015 Matthew Valli. All rights reserved.
//

#include "FileWriter.h"

using namespace std;


// CONSTRUCTORS
FileWriter::FileWriter() {
    
}

FileWriter::FileWriter(string fileName) {
    // Store the Name/Path of the file
    mFileName = fileName;
}

FileWriter::~FileWriter() { }



// CONVENIENCE METHODS
void FileWriter::writeLine(string line, ios_base::openmode mode, bool addNewLine, bool outputToConsole) {
    // Open a connection to a file, creates a new file if non-existent
    mFile.open(mFileName, mode);
    
    
    // Add the line to the file
    mFile << line;
    if (addNewLine) { mFile << endl; }
    
    // Output the line to the console
    if (outputToConsole) {
        cout << line;
        if (addNewLine) cout << endl;
    }
    
    // Close the file
    mFile.close();
}

// Append
void FileWriter::append(string line, bool addNewLine, bool outputToConsole) {
    writeLine(line, ios_base::app, addNewLine, outputToConsole);
}

void FileWriter::append(string line) {
    append(line, false, false);
}


// Overwrite
void FileWriter::overwrite(string line) {
    overwrite(line, false, false);
}

void FileWriter::overwrite(string line, bool addNewLine, bool outputToConsole) {
    writeLine(line, ios_base::app, addNewLine, outputToConsole);
}
