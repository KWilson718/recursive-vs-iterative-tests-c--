////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Algorithm Execution Time Comparison Class Implementation
// By Kyle Wilson
// 
// The stated purpose of this class is to compare the execution time of four algorithms
//  - Each algorithm works to compute a provided base that is then multiplied to the power of a provided exponent
//  - Four public variables can then be accessed with the execution times for further analysis

// Include for header file
#include "algorithms.h"

// Include for time keeping library
#include <chrono>

// STD method declarations
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Basic constructor declaration, sets everything to the correct form of zero
Algorithms::Algorithms() {
    this->_doubleIterativeTime = 0.0;
    this->_doubleRecursiveTime = 0.0;
    this->_integerIterativeTime = 0;
    this->_integerRecursiveTime = 0;
}

// Runs helper functions to calculate the time of each algorithm when running to the power of a provided exponent
void Algorithms::findTimes(long long exponent) {
    
    calculateDoubleIterative(_DOUBLE_BASE, exponent);

    calculateDoubleRecursive(_DOUBLE_BASE, exponent);

    calculateIntegerIterative(_INTEGER_BASE, exponent);

    calculateIntegerRecursive(_INTEGER_BASE, exponent);

}

// Resets each time to zero to prevent confusion
void Algorithms::clearTimes() {
    this->_doubleIterativeTime = 0.0;
    this->_doubleRecursiveTime = 0.0;
    this->_integerIterativeTime = 0;
    this->_integerRecursiveTime = 0;
}

// Function used to wrap an algorithm & report out execution time to member variable
void Algorithms::calculateDoubleIterative(long double base, long long exponent) {
    // Starts clock
    auto start = high_resolution_clock::now();

    // Executes algorithm
    long double tmpVal = doubleIterativeAlg(base, exponent);

    // Ends clock
    auto end = high_resolution_clock::now();

    // Sets appropriate variable to the time difference in nanoseconds
    this->_doubleIterativeTime = duration_cast<nanoseconds>(end - start).count();
}

// Function used to wrap an algorithm & report out execution time to member variable
void Algorithms::calculateDoubleRecursive(long double base, long long exponent) {
    // Starts clock
    auto start = high_resolution_clock::now();

    // Executes algorithm
    long double tmpVal = doubleRecursiveAlg(base, exponent);

    // Ends clock
    auto end = high_resolution_clock::now();

    // Sets appropriate variable to the time difference in nanoseconds
    this->_doubleRecursiveTime = duration_cast<nanoseconds>(end - start).count();
}

// Function used to wrap an algorithm & report out execution time to member variable
void Algorithms::calculateIntegerIterative(long long base, long long exponent) {
    // Starts clock
    auto start = high_resolution_clock::now();

    // Executes algorithm
    long long tmpVal = integerIterativeAlg(base, exponent);

    // Ends clock
    auto end = high_resolution_clock::now();

    // Sets appropriate variable to the time difference in nanoseconds
    this->_integerIterativeTime = duration_cast<nanoseconds>(end - start).count();
}

// Function used to wrap an algorithm & report out execution time to member variable
void Algorithms::calculateIntegerRecursive(long long base, long long exponent) {
    // Starts clock
    auto start = high_resolution_clock::now();

    // Executes algorithm
    long long tmpVal = integerRecursiveAlg(base, exponent);

    // Ends clock
    auto end = high_resolution_clock::now();

    // Sets appropriate variable to the time difference in nanoseconds
    this->_integerRecursiveTime = duration_cast<nanoseconds>(end - start).count();
}

// Provided algorithm to analyze - Iterative Design using Doubles
long double Algorithms::doubleIterativeAlg(long double base, long long exponent) {
    long double retVal = 1.0;
	if (exponent < 0) {
		return 1.0 / doubleIterativeAlg(base, -exponent);
	} else {
		for (long long i = 0; i < exponent; i++) {
			retVal *= base;
        }
	}
	return retVal;
}

// Provided algorithm to analyze - Recursive Design using Doubles
long double Algorithms::doubleRecursiveAlg(long double base, long long exponent) {
    if (exponent < 0) {
		return 1.0 / doubleRecursiveAlg(base, -exponent);
	} else if (exponent == 0) {
		return 1.0;
	} else {
		return base * doubleRecursiveAlg(base, exponent - 1);
	}

}

// Provided algorithm to analyze - Iterative Design mutated to accept Integers
long long Algorithms::integerIterativeAlg(long long base, long long exponent) {
    long long retVal = 1;
    if (exponent < 0) {
        return integerIterativeAlg(base, -exponent);
    } else {
        for (long long i = 0; i < exponent; i++) {
            retVal *= base;
        }
    }
    return retVal;
}

// Provided algorithm to analyze - Recursive Design mutated to accept Integers
long long Algorithms::integerRecursiveAlg(long long base, long long exponent) {
    if (exponent < 0) {
        return 1 / integerRecursiveAlg(base, -exponent);
    } else if (exponent == 0) {
        return 1;
    } else {
        return base * integerRecursiveAlg(base, exponent - 1);
    }
}


