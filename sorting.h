#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void selectionSort(int arr[], int size);
void quickSort(int* arr, int start, int end);
void countingSort(int arr_o[], int size);
void shellSort(int arr[], int size);
void radixSort(int arr[], int size);
void heapSort(int arr[], int size);

long long measureBubbleSortComparisons(int arr[], int size);
long long measureInsertionSortComparisons(int arr[], int size);
long long measureMergeSortComparisons(int arr[], int left, int right, long long& countComp);
long long measureSelectionSortComparisons(int arr[], int size);
long long measureQuickSortComparisons(int* arr, int start, int end, long long& countComp);
long long measureCountingSortComparisons(int arr_o[], int size);
long long measureShellSortComparisons(int arr[], int size);
long long measureRadixSortComparisons(int arr[], int size);
long long measureHeapSortComparisons(int arr[], int size);
#endif
