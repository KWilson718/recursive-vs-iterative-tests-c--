////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Algorithm Execution Time Comparison Class
// By Kyle Wilson
// 
// The stated purpose of this class is to compare the execution time of four algorithms
//  - Each algorithm works to compute a provided base that is then multiplied to the power of a provided exponent
//  - Four public variables can then be accessed with the execution times for further analysis

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms {

public:
    // Constant values provided by assignment
    const long double _DOUBLE_BASE = 2.718281828459045091;
    const long long _INTEGER_BASE = 1000003;

    // Four member variables that can be accessed for analysis
    long long _doubleIterativeTime;
    long long _doubleRecursiveTime;
    long long _integerIterativeTime;
    long long _integerRecursiveTime;

    // Constructor
    Algorithms(); 
    
    // Takes in a number to use and sets each variable's time to the updated one
    void findTimes(long long exponent);  

    // Sets each member variable to zero, as to not cause confusion
    void clearTimes();  

private:

    // Finds the time for DoubleIterative
    void calculateDoubleIterative(long double base, long long exponent);

    // Finds the time for DoubleRecursive
    void calculateDoubleRecursive(long double base, long long exponent);

    // Finds the time for IntegerIterative
    void calculateIntegerIterative(long long base, long long exponent);

    // Finds the time for IntegerRecursive
    void calculateIntegerRecursive(long long base, long long exponent);

    // Algorithm for DoubleIterative
    long double doubleIterativeAlg(long double base, long long exponent);

    // Algorithm for DoubleRecursive
    long double doubleRecursiveAlg(long double base, long long exponent);

    // Algorithm for IntegerIterative
    long long integerIterativeAlg(long long base, long long exponent);

    // Algorithm for IntegerRecursive
    long long integerRecursiveAlg(long long base, long long exponent);

};

#endif