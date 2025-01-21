////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Measuring the variance in execution time between Recursive & Iterative design, with both Int and Double based types
// By Kyle Wilson
// 
// This program works to measure the time it takes to execute four different algorithms
//  - Each algorithm computes a base variable to the power of a provided exponent
//  - This program starts the exponent at 0, and then increases until the program crashes
//  - Data about executions times (in nanoseconds) are written to a csv file named output.csv
// 
// This main.cpp does some of the lightweight work to use the algorithms class in order to fully analyze everything


// Basic includes
#include <iostream>
#include <fstream>
#include <string>

// Include of custom class
#include "algorithms.h"

// STD library methods
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::string;
using std::ios;

// File output function declarations
void initializeCSV(const string &fileName);
void appendToCSV(const string &fileName, long long exponent, double doubleIterativeTime, double doubleRecursiveTime, double integerIterativeTime, double integerRecursiveTime);

// Main function of program
int main() {

    // Declares algorithm object
    Algorithms AlgorithmHandler = Algorithms();

    // Declares useful variables for within for loop
    long long exponent;
    string filename = "output.csv";

    // Creates the csv file
    initializeCSV(filename);

    // Infinite Loop to test variables as high as possible
    for (exponent = 0; exponent > -1; exponent++) {
        // Calls the created algorithms object to calculate the time for all four algorithms & set the values of them to the object's public variables
        AlgorithmHandler.findTimes(exponent);

        // Outputs the values from this exponent's execution to the console
        cout << "Times for Exponent " << exponent << ": " << AlgorithmHandler._doubleIterativeTime << ", " << AlgorithmHandler._doubleRecursiveTime << ", " << AlgorithmHandler._integerIterativeTime << ", " << AlgorithmHandler._integerRecursiveTime << endl;

        // Adds the values from this exponent's execution to the csv file
        appendToCSV(filename, exponent, AlgorithmHandler._doubleIterativeTime, AlgorithmHandler._doubleRecursiveTime, AlgorithmHandler._integerIterativeTime, AlgorithmHandler._integerRecursiveTime);

        // Resets the times to ensure everything output is fresh & not from previous exponent
        AlgorithmHandler.clearTimes();
    }

    // Will not get hit (program will crash by design), however would make the program close safely
    return 0;
}

// Function to create csv file and verify that it can be opened
void initializeCSV(const string &fileName) {
    ofstream file(fileName); // Create file

    // Tests opening file, outputting an error if it can't
    if (!file.is_open()) {
        cerr << "Unable to open file for writing." << endl;
    } else {
        file.close();
    }
}

// Function to output a row of data to the csv file
void appendToCSV(const string &fileName, long long exponent, double doubleIterativeTime, double doubleRecursiveTime, double integerIterativeTime, double integerRecursiveTime) {
    ofstream file(fileName, ios::app);

    if (!file.is_open()) { // Handles ouputting an error if it can't open the file
        cerr << "Unable to open file for appending." << endl;
    } else { // Adds the provided data to the file now that it is open, and then closes it for safety
        file << exponent << ',' << doubleIterativeTime << ',' << doubleRecursiveTime << ',' << integerIterativeTime << ',' << integerRecursiveTime << '\n';
        file.close();
    }
}