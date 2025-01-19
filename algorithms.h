#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms {

public:
    long long _doubleIterativeTime;
    long long _doubleRecursiveTime;
    long long _integerIterativeTime;
    long long _integerRecursiveTime;

    Algorithms(); // constructor
    
    // Takes in a number to use and sets each variable's time to the updated one, returns a boolean if true
    bool findTimes(long long n);    

private:

    // Finds the time for DoubleIterative
    void calculateDoubleIterative(long long n);

    // Finds the time for DoubleRecursive
    void calculateDoubleRecursive(long long n);

    // Finds the time for IntegerIterative
    void calculateIntegerIterative(long long n);

    // Finds the time for IntegerRecursive
    void calculateIntegerRecursive(long long n);

};

#endif