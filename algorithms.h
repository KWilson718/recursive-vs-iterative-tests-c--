#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms {

public:
    const long double _DOUBLE_BASE = 2.718281828459045091;
    const long long _INTEGER_BASE = 1000003;

    long long _doubleIterativeTime;
    long long _doubleRecursiveTime;
    long long _integerIterativeTime;
    long long _integerRecursiveTime;

    Algorithms(); // constructor
    
    // Takes in a number to use and sets each variable's time to the updated one, returns a boolean if true
    void findTimes(long long exponent);    

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