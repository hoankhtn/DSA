#include <iostream>
using namespace std;

//Function for duplicating
int* duplicate(int*& arr, int size) {
    if (arr == nullptr || size <= 0) {
        cout << "Invalid data. Can't duplicate!" << endl;
        return nullptr;
    }
    
    int* newArr = new int[size];
    for (int i = 0; i < size; i ++) {
        newArr[i] = arr[i];
    }
    return newArr;
}