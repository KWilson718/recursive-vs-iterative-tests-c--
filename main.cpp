#include <iostream>
#include <fstream>
#include <string>

#include "algorithms.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::string;
using std::ios;

void initializeCSV(const string &fileName);
void appendToCSV(const string &fileName, long long exponent, double doubleIterativeTime, double doubleRecursiveTime, double integerIterativeTime, double integerRecursiveTime);

int main() {

    Algorithms AlgorithmHandler = Algorithms();

    long long exponent;
    string filename = "output.csv";

    initializeCSV(filename);

    // Infinite Loop to test variables as high as possible
    for (exponent = 0; exponent > -1; exponent++) {
        AlgorithmHandler.findTimes(exponent);

        cout << "Times for Exponent " << exponent << ": " << AlgorithmHandler._doubleIterativeTime << ", " << AlgorithmHandler._doubleRecursiveTime << ", " << AlgorithmHandler._integerIterativeTime << ", " << AlgorithmHandler._integerRecursiveTime << endl;

        appendToCSV(filename, exponent, AlgorithmHandler._doubleIterativeTime, AlgorithmHandler._doubleRecursiveTime, AlgorithmHandler._integerIterativeTime, AlgorithmHandler._integerRecursiveTime);

        AlgorithmHandler.clearTimes();
    }

    return 0;
}

void initializeCSV(const string &fileName) {
    ofstream file(fileName); // Create file

    // Tests opening file, outputting an error if it can't
    if (!file.is_open()) {
        cerr << "Unable to open file for writing." << endl;
    } else {
        file.close();
    }
}

void appendToCSV(const string &fileName, long long exponent, double doubleIterativeTime, double doubleRecursiveTime, double integerIterativeTime, double integerRecursiveTime) {
    ofstream file(fileName, ios::app);

    if (!file.is_open()) { // Handles ouputting an error if it can't open the file
        cerr << "Unable to open file for appending." << endl;
    } else {
        file << exponent << ',' << doubleIterativeTime << ',' << doubleRecursiveTime << ',' << integerIterativeTime << ',' << integerRecursiveTime << '\n';
        file.close();
    }
}