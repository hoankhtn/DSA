#include "sorting.h"
#include <iostream>

//Insertion Sort
void insertionSort(int arr[], int size) {
    
}

/************************************************ */

//The function to count the number of comparisons in Insertion Sort 
long long measureInsertionSortComparisons(int arr[], int size) {
    
}

/************************************************ */

//Bubble Sort
void bubbleSort(int arr[], int size) {
    
}

/************************************************ */

//The function to count the number of comparisons in Bubble Sort 
long long measureBubbleSortComparisons(int arr[], int size) {
    
}

/************************************************ */

//Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

/************************************************ */

//The function to count the number of comparisons in Selection Sort 
long long measureSelectionSortComparisons(int arr[], int size) {
    long long comparisons = 0;
    for (int i = 0; i < n; i++, comparisons++) {
        int min = i;
        for (int j = i + 1; j < n; j++, comparisons++) {
            if (arr[j] < arr[min]) {
                min = j;
                comparisons++;
            }
        }
        swap(arr[min], arr[i]);
    }
    return comparisons;
}

/************************************************ */

//Quick Sort
int medianOfThree(int* arr, int start, int end) {
    int mid = first + (last - first) / 2;

    if (arr[mid] < arr[first]) swap(arr[mid], arr[first]);
    if (arr[last] < arr[first]) swap(arr[last], arr[first]);
    if (arr[mid] < arr[last]) swap(arr[mid], arr[last]);

    int pivot = arr[last]; 
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quickSort(int* arr, int start, int end) {
    if (first < last) {
        int pivotIndex = medianOfThree(arr, first, last);
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

/************************************************ */

//Functions to count the number of comparisons in Quick Sort 
int measureMedianOfThreeComparisons(int* arr, int start, int end, long long& countComp) {
    int mid = first + (last - first) / 2;

    countComp++;
    if (arr[mid] < arr[first]) swap(arr[mid], arr[first]);
    countComp++;
    if (arr[last] < arr[first]) swap(arr[last], arr[first]);
    countComp++;
    if (arr[mid] < arr[last]) swap(arr[mid], arr[last]);

    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++, countComp++) {
        countComp++;
        if (arr[j] < pivot) {
            countComp++;
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

long long measureQuickSortComparisons(int* arr, int start, int end, long long& countComp) {
    if (first < last) {
    countComp++;
        int pivotIndex = measureMedianOfThreeComparisons(arr, first, last, countComp);
        measureQuickSortComparisons(arr, first, pivotIndex - 1, countComp);
        measureQuickSortComparisons(arr, pivotIndex + 1, last, countComp);
    }
    return countComp;
}

/************************************************ */

//Merge Sort
void merge(int arr[], int left, int middle, int right) {
    
}

void mergeSort(int arr[], int left, int right) {
    
}

/************************************************ */

//Functions to count the number of comparisons in Merge Sort 

long long measureMergeComparisons(int arr[], int left, int middle, int right, long long& countComp) {
    
}

long long measureMergeSortComparisons(int arr[], int left, int right, long long& countComp) {
    
}

/************************************************ */

//Heap Sort
void heapify(int arr[], int size, int i) {
    
}

void heapSort(int arr[], int size) {

}

/************************************************ */

//Functions to count the number of comparisons in Heap Sort 

long long measureHeapifyComparisons(int arr[], int size, int i) {
    
}

long long measureHeapSortComparisons(int arr[], int size) {
    
}

/************************************************ */

// Shell Sort 
void shellSort(int arr[], int size) {
    
}

/************************************************ */

//The function to count the number of comparisons in Shell Sort 
long long measureShellSortComparisons(int arr[], int size) {
    
}

/************************************************ */

//Find Maximum Function
int getMax(int arr[], int size) {
    
}

/************************************************ */

//Radix Sort
void countingSort_r(int arr[], int size, int exp) {
    
}

void radixSort(int arr[], int size) {
    
}

/************************************************ */

//Functions to count the number of comparisons in Radix Sort
long long measureCountingSort_rComparisons(int arr[], int size, int exp) {
    
}

long long  measureRadixSortComparisons(int arr[], int size) {
    
}

/************************************************ */

//Counting Sort
void countingSort(int arr_o[], int size) {
    
}

/************************************************ */

//The function to count the number of comparisons in Counting Sort
long long  measureCountingSortComparisons(int arr_o[], int size) {
    
}
