#ifndef TIMING_AND_COMPARISON_H
#define TIMING_AND_COMPARISON_H

#include <iostream>
using namespace std;

long long countComparisons(string& algorithm, int* arr, int size, long long& comparison);
double measureTime(const string& algorithm, int* arr, int size);

#endif