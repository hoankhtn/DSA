#include <iostream>
#include <chrono>
#include "sorting.h"
#include "duplicate.h"
using namespace std;

//Measure the execution time in sorting algorithms
double measureTime(const string& algorithm, int* arr, int size) {
    int* tempArr = duplicate(arr, size);
    
    if (!tempArr) return -1;
    auto start = chrono::high_resolution_clock::now();

    if (algorithm == "bubble-sort") {
        bubbleSort(tempArr, size);
    } else if (algorithm == "selection-sort") {
        selectionSort(tempArr, size);
    } else if (algorithm == "insertion-sort") {
        insertionSort(tempArr, size);
    } else if (algorithm == "heap-sort") {
        heapSort(tempArr, size);
    } else if (algorithm == "merge-sort") {
        mergeSort(tempArr, 0, size - 1);
    } else if (algorithm == "quick-sort") {
        quickSort(tempArr, 0, size - 1);
    } else if (algorithm == "radix-sort") {
        radixSort(tempArr, size);
    } else if (algorithm == "shell-sort") {
        shellSort(tempArr, size);
    } else if (algorithm == "counting-sort") {
        countingSort(tempArr, size);
    } else {
        delete[] tempArr;
        return -1;
    }

    auto end = chrono::high_resolution_clock::now();
    double runningTime = chrono::duration<double, milli>(end - start).count();

    delete[] tempArr;
    return runningTime;
}

/***************************************************** */

//Measure the number of comparisons in sorting algorithms
long long countComparisons(string& algorithm, int* arr, int size, long long& comparison) {
    comparison = 0;
    if (algorithm == "bubble-sort") {
        comparison = measureBubbleSortComparisons(arr, size);
    } else if (algorithm == "selection-sort") {
        comparison = measureSelectionSortComparisons(arr, size);
    } else if (algorithm == "insertion-sort") {
        comparison = measureInsertionSortComparisons(arr, size);
    } else if (algorithm == "heap-sort") {
        comparison = measureHeapSortComparisons(arr, size);
    } else if (algorithm == "merge-sort") {
        comparison = measureMergeSortComparisons(arr, 0, size - 1, comparison);
    } else if (algorithm == "quick-sort") {
        comparison = measureQuickSortComparisons(arr, 0, size - 1, comparison);
    } else if (algorithm == "radix-sort") {
        comparison = measureRadixSortComparisons(arr, size);
    } else if (algorithm == "shell-sort") {
        comparison = measureShellSortComparisons(arr, size);
    } else if (algorithm == "counting-sort") {
        comparison = measureCountingSortComparisons(arr, size);
    } else {
        cout << "Error: Unknown sorting algorithm: " << algorithm << endl;
        return -1; 
    }
    
    return comparison;
}