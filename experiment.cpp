#include <iostream>
#include <fstream>
#include "duplicate.h"
#include "timing_and_comparison.h"
#include "data.h"
#include <chrono>
using namespace std;

//The function to run experiment
void Experiment(const string& fileName) {
    ofstream fileOut(fileName);
    if (!fileOut.is_open()) {
        cout << "Can't open file " << fileName;
        return;
    }
    string order[] = {"randomized", "sorted", "reverse sorted", "nearly sorted"};
    int size[] = {10000, 30000, 50000, 100000, 300000, 500000};
    string algorithm[] = {"selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort"};
    for (int i = 0; i < 4; i ++) {//data order
        for (int j = 0; j < 6; j ++) {//data size
            int* arr1 = new int[size[j]];
            GenerateData(arr1, size[j], i);
            for (int k = 0; k < 9; k ++) {//algorithm
                int* arr2 = duplicate(arr1, size[j]);
                
                double runningTime = measureTime(algorithm[k], arr2, size[j]);
                long long comparison = countComparisons(algorithm[k], arr2, size[j], comparison);

                fileOut << order[i] << "," << size[j] << "," << algorithm[k] << "," << runningTime << "," << comparison << "\n";

                delete[] arr2;
            }
            delete[] arr1;
        }
    }
    fileOut.close();
    cout << "Experiment completed!. Result saved in" << fileName;
}

int main() {
    Experiment("experiment.txt");
    return 0;
}