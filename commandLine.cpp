#include "sorting.h"
#include "modeFile.h"
#include "timing_and_comparison.h"
#include "data.h"
#include "duplicate.h"
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

//Command Line 1
void processCommandLine1(string& mode, string& algorithm, const string& fileName, string& parameter) {

    if (mode != "-a") {
        cout << "Invalid mode. Use -a for algorithm mode." << endl;
        return;
    }

    if (parameter != "-time" && parameter != "-comp" && parameter != "-both") {
        cout << "Invalid parameter name. Please check parameter name!";
        return;
    }

    int* arr = nullptr;
    int size = 0;

    readFromFile(fileName, arr, size);
    cout << "ALGORITHM MODE" << "\n";
    cout << "Algorithm: " << algorithm << "\n";
    cout << "Input file: " << fileName << "\n";
    cout << "Input size: " << size << "\n";
    cout << "---------------------------------------------\n";

    if (parameter == "-time" || parameter == "-both") {
        double runningTime = measureTime(algorithm, arr, size);
        cout << "Running Time: " << runningTime << " " << "milisecond" << endl;
    }
    if (parameter == "-comp" || parameter == "-both") {
        long long comparison = countComparisons(algorithm, arr, size, comparison);
        cout << "Comparisons: " << comparison << " " << "comparisons";
    }
    
    writeToFile("output.txt", arr, size);
    delete[] arr;
}

/***************************************************** */

//Command Line 2
void processCommandLine2(string& mode, string& algorithm, int &size, string& order, string& parameter) {
    if (size <= 0) {
        cout << "Invalid input size. Please check input size!";
        return;
    }

    if (mode != "-a") {
        cout << "Invalid mode. Use -a for algorithm mode." << endl;
        return;
    }

    if (parameter != "-time" && parameter != "-comp" && parameter != "-both") {
        cout << "Invalid parameter name. Please check parameter name!";
        return;
    }

    int* arr = new int[size];

    if (order == "-rand") {
        GenerateRandomData(arr, size);
    }
    else if (order == "-nsorted") {
        GenerateNearlySortedData(arr, size);
    }
    else if (order == "-sorted") {
        GenerateSortedData(arr, size);
    }
    else if (order == "-rev") {
        GenerateReverseData(arr, size);
    }

    writeToFile("input.txt", arr, size);
    cout << "ALGORITHM MODE" << "\n";
    cout << "Algorithm: " << algorithm << "\n";
    cout << "Input size: " << size << "\n";
    cout << "Input order: " << order << "\n";
    cout << "---------------------------------------------\n";

    if (parameter == "-time" || parameter == "-both") {
        double runningTime = measureTime(algorithm, arr, size);
        cout << "Running Time: " << runningTime << " " << "milisecond" << endl;
    }

    if (parameter == "-comp" || parameter == "-both") {
        long long comparison = countComparisons(algorithm, arr, size, comparison);
        cout << "Comparisons: " << comparison << " " << "comparisons";
    }

    writeToFile("output.txt", arr, size);

    delete[] arr;
}

/***************************************************** */

//Command Line 3
void processCommandLine3(string& mode, string& algorithm, int& size, string& parameter) {
    if (size <= 0) {
        cout << "Invalid input size. Please check input size!";
        return;
    }

    if (parameter != "-time" && parameter != "-comp" && parameter != "-both") {
        cout << "Invalid parameter name. Please check parameter name!";
        return;
    }

    string order[4] = {"Randomize", "Sorted", "Reverse", "Nearly Sorted"};
    string fileNames[4] = { 
        "input_1.txt",
        "input_3.txt",
        "input_4.txt",
        "input_2.txt"
    };

    if (mode != "-a") {
        cout << "Invalid mode. Use -a for algorithm mode.";
        return;
    }

    cout << "ALGORITHM MODE" << "\n";
    cout << "Algorithm: " << algorithm << "\n";
    cout << "Input size: " << size << "\n";
    cout << "---------------------------------------------\n\n";

    int* arr = new int[size];

    for (int i = 0; i < 4; i ++) {
        cout << "Input order: " << order[i] << endl;

        GenerateData(arr, size, i);

        writeToFile(fileNames[i], arr, size);

        int* tempArr = duplicate(arr, size);
        cout << "---------------------------------------------\n";

        if (parameter == "-time" || parameter == "-both") {
            double runningTime = measureTime(algorithm, tempArr, size);
            cout << "Running time: " << runningTime << " " << "milisecond" << endl;
        }

        if (parameter == "-comp" || parameter == "-both") {
            long long comparison = countComparisons(algorithm, tempArr, size, comparison);
            cout << "Comparisons: " << comparison << " " << "comparisons";
        }

        delete[] tempArr;

        cout << "\n\n";
    }
    
    delete[] arr;
}

/***************************************************** */

//Command Line 4
void processCommandLine4(string& mode, string& algorithm1, string& algorithm2, const string& fileName) {
    if (mode != "-c") {
        cout << "Invalid mode. Use -c for comparison mode." << endl;
        return;
    }
    
    int* arr = nullptr;
    int size = 0;

    readFromFile(fileName, arr, size);

    cout << "COMPARE MODE" << "\n";
    cout << "Algorithms: " << algorithm1 << " " << "|" << " " << algorithm2 << "\n";
    cout << "Input file: " << fileName << "\n";
    cout << "Input size: " << size << "\n";
    cout << "---------------------------------------------\n";

    int* newArr = duplicate(arr, size);
    double runningTime1 = measureTime(algorithm1, arr, size), runningTime2 = measureTime(algorithm2, arr, size);
    long long comparisons1 = countComparisons(algorithm2, newArr, size, comparisons1), comparisons2 =  countComparisons(algorithm2, newArr, size, comparisons2);
    cout << "Running time: " << runningTime1 << " " << "milisecond" << " " << "|" << " " << runningTime2 << " " << "milisecond" << endl;
    cout << "Comparisons: " << comparisons1 << " " << "comparisons" << " " << "|" << " " << comparisons2 << " " << "comparisons";

    delete[] arr;
    delete[] newArr;
}

/***************************************************** */

//Command Line 5
void processCommandLine5(string& mode, string& algorithm1, string& algorithm2, int &size, string& order) {
    if (size <= 0) {
        cout << "Invalid input size. Please check input size!";
        return;
    }

    if (mode != "-c") {
        cout << "Invalid mode. Use -c for algorithm mode." << endl;
        return;
    }

    int* arr = new int[size];
    
    if (order == "-rand") {
        GenerateRandomData(arr, size);
    }

    else if (order == "-nsorted") {
        GenerateNearlySortedData(arr, size);
    }

    else if (order == "-sorted") {
        GenerateSortedData(arr, size);
    }

    else if (order == "-rev") {
        GenerateReverseData(arr, size);
    }

    else {
        cout << "Invalid input order. Please use -rand, -sorted, -nsorted or -rev." << endl;
        delete[] arr;
        return;
    }
    
    writeToFile("input.txt", arr, size);
    cout << "COMPARE MODE" << "\n";
    cout << "Algorithm: " << algorithm1 << " " << "|" << " " << algorithm2 << "\n";
    cout << "Input size: " << size << "\n";
    cout << "Input order: " << order << "\n";
    cout << "---------------------------------------------\n";

    int* newArr = duplicate(arr, size);
    double runningTime1 = measureTime(algorithm1, arr, size), runningTime2 = measureTime(algorithm2, arr, size);
    long long comparisons1 = countComparisons(algorithm2, newArr, size, comparisons1), comparisons2 = countComparisons(algorithm2, newArr, size, comparisons2) ;
    cout << "Running time: " << runningTime1 << " " << "milisecond" << " " << "|" << " " << runningTime2 << " " << "milisecond" << endl;
    cout << "Comparisons: " << comparisons1 << " " << "comparisons" << " " << "|" << " " << comparisons2 << " " << "comparisons";
    
    delete[] arr;
    delete[] newArr;
}


