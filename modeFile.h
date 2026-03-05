#ifndef MODEFILE_H
#define MODEFILE_H

#include <iostream>
using namespace std;

void readFromFile(const string& fileName, int*& arr, int& size);
void writeToFile(const string& fileName, int* arr, int size);
#endif