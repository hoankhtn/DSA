#include <iostream>
#include <fstream>
using namespace std;

// The function to read from file
void readFromFile(const string& fileName, int*& arr, int& size) {
    ifstream fileIn(fileName);

    if (!fileIn.is_open()) {
        cout << "Can't open file " << fileName << endl;
        return;
    }

    fileIn >> size;

    if (size <= 0) {
        cout << "Please check my file. Data size is invalid!";
        return;
    }

    delete[] arr;

    arr = new int[size];

    for (int i = 0; i < size; i ++) {
        if (!(fileIn >> arr[i])) {
            delete[] arr;
            arr = NULL;
            size = 0;
            return;
        }
    }
    
    fileIn.close();
}

/************************************************* */

//The function to write to file
void writeToFile(const string& fileName, int* arr, int size) {
    if (arr == NULL || size <= 0) {
        cout << "Invalid array data. Can't write to file" << fileName << endl;
        return;
    }
    
    ofstream fileOut(fileName);
    if (!fileOut.is_open()) {
        cout << "Can't open file " << fileName;
        return;
    }

    fileOut << size << endl;
    for (int i = 0; i < size; i ++) {
        fileOut << arr[i] << " ";
    }

    fileOut.close();
}