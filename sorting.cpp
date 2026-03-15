#include "sorting.h"
#include <iostream>

//Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/************************************************ */

long long measureInsertionSortComparisons(int arr[], int size) {
    long long countComp = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (++countComp && j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return countComp;
}

/************************************************ */

//Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j]   = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/************************************************ */

long long measureBubbleSortComparisons(int arr[], int size) {
    long long countComp = 0;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            ++countComp;
            if (arr[j] > arr[j + 1]) {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return countComp;
}

/************************************************ */

//Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
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
    for (int i = 0; i < size; i++, comparisons++) {
        int min = i;
        for (int j = i + 1; j < size; j++, comparisons++) {
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
    int mid = start + (end - start) / 2;

    if (arr[mid] < arr[start]) swap(arr[mid], arr[start]);
    if (arr[end] < arr[start]) swap(arr[end], arr[start]);
    if (arr[mid] < arr[end]) swap(arr[mid], arr[end]);

    int pivot = arr[end]; 
    int i = start - 1;

    for (int j = start; j < end; j++) {
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
        int pivotIndex = medianOfThree(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

/************************************************ */

//Functions to count the number of comparisons in Quick Sort 
int measureMedianOfThreeComparisons(int* arr, int start, int end, long long& countComp) {
    int mid = start + (end - start) / 2;

    countComp++;
    if (arr[mid] < arr[start]) swap(arr[mid], arr[start]);
    countComp++;
    if (arr[end] < arr[start]) swap(arr[end], arr[start]);
    countComp++;
    if (arr[mid] < arr[end]) swap(arr[mid], arr[end]);

    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++, countComp++) {
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
        int pivotIndex = measureMedianOfThreeComparisons(arr, start, end, countComp);
        measureQuickSortComparisons(arr, start, pivotIndex - 1, countComp);
        measureQuickSortComparisons(arr, pivotIndex + 1, end, countComp);
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

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp    = arr[i];
        arr[i]      = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0]   = arr[i];
        arr[i]   = temp;
        heapify(arr, i, 0);
    }
}

/************************************************ */


long long measureHeapifyComparisons(int arr[], int size, int i) {
    long long countComp = 0;
    while (true) {
        int largest = i;
        int left    = 2 * i + 1;
        int right   = 2 * i + 2;

        if (++countComp && left < size && arr[left] > arr[largest])
            largest = left;
        if (++countComp && right < size && arr[right] > arr[largest])
            largest = right;

        if (largest == i) break;

        int temp     = arr[i];
        arr[i]       = arr[largest];
        arr[largest] = temp;
        i = largest;
    }
    return countComp;
}

long long measureHeapSortComparisons(int arr[], int size) {
    long long countComp = 0;

    // Build max-heap
    for (int i = size / 2 - 1; i >= 0; i--)
        countComp += measureHeapifyComparisons(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0]   = arr[i];
        arr[i]   = temp;
        countComp += measureHeapifyComparisons(arr, i, 0);
    }

    return countComp;
}

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
