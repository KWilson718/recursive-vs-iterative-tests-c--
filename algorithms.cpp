#include "algorithms.h"

#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

Algorithms::Algorithms() {
    this->_doubleIterativeTime = 0.0;
    this->_doubleRecursiveTime = 0.0;
    this->_integerIterativeTime = 0;
    this->_integerRecursiveTime = 0;
}

void Algorithms::findTimes(long long exponent) {
    
    calculateDoubleIterative(_DOUBLE_BASE, exponent);

    calculateDoubleRecursive(_DOUBLE_BASE, exponent);

    calculateIntegerIterative(_INTEGER_BASE, exponent);

    calculateIntegerRecursive(_INTEGER_BASE, exponent);

}

void Algorithms::clearTimes() {
    this->_doubleIterativeTime = 0.0;
    this->_doubleRecursiveTime = 0.0;
    this->_integerIterativeTime = 0;
    this->_integerRecursiveTime = 0;
}

void Algorithms::calculateDoubleIterative(long double base, long long exponent) {
    auto start = high_resolution_clock::now();

    long double tmpVal = doubleIterativeAlg(base, exponent);

    auto end = high_resolution_clock::now();

    this->_doubleIterativeTime = duration_cast<nanoseconds>(end - start).count();
}

void Algorithms::calculateDoubleRecursive(long double base, long long exponent) {
    auto start = high_resolution_clock::now();

    long double tmpVal = doubleRecursiveAlg(base, exponent);

    auto end = high_resolution_clock::now();

    this->_doubleRecursiveTime = duration_cast<nanoseconds>(end - start).count();
}

void Algorithms::calculateIntegerIterative(long long base, long long exponent) {
    auto start = high_resolution_clock::now();

    long long tmpVal = integerIterativeAlg(base, exponent);

    auto end = high_resolution_clock::now();

    this->_integerIterativeTime = duration_cast<nanoseconds>(end - start).count();
}

void Algorithms::calculateIntegerRecursive(long long base, long long exponent) {
    auto start = high_resolution_clock::now();

    long long tmpVal = integerRecursiveAlg(base, exponent);

    auto end = high_resolution_clock::now();

    this->_integerRecursiveTime = duration_cast<nanoseconds>(end - start).count();
}

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

long double Algorithms::doubleRecursiveAlg(long double base, long long exponent) {
    if (exponent < 0) {
		return 1.0 / doubleRecursiveAlg(base, -exponent);
	} else if (exponent == 0) {
		return 1.0;
	} else {
		return base * doubleRecursiveAlg(base, exponent - 1);
	}

}

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

long long Algorithms::integerRecursiveAlg(long long base, long long exponent) {
    if (exponent < 0) {
        return 1 / integerRecursiveAlg(base, -exponent);
    } else if (exponent == 0) {
        return 1;
    } else {
        return base * integerRecursiveAlg(base, exponent - 1);
    }
}


