#include "sorting.h"
#include "modeFile.h"
#include "timing_and_comparison.h"
#include "data.h"
#include "duplicate.h"
#include "commandLine.h"
#include <iostream>
#include <chrono>
#include <sstream>
using namespace std;

//Check of number
bool isNumber(const string& input) {
    if (input.empty()) return false;
    int value;
    stringstream ss(input);
    ss >> value;
    return !ss.fail() && ss.eof();
}

/****************************************************** */
//Main function

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Insufficient parameters. Please enter sufficient parameters: " << endl;
        cout << "[Execution file] -a [Algorithm] [Input filename] [Output parameter]" << endl;
        cout << "or" << endl;
        cout << "[Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter]" << endl;
        cout << "or" << endl;
        cout << "[Execution file] -a [Algorithm] [Input size] [Output parameter]" << endl;
        cout << "or" << endl;
        cout << "[Execution file] -c [Algorithm 1] [Algorithm 2] [Input filename]" << endl;
        cout << "or" << endl;
        cout << "[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
        return 1;
    }

    string mode = argv[1];
    if (mode == "-a") {
        if (argc == 5 && !isNumber(argv[3])) {
            string algorithm = argv[2];
            string fileName = argv[3];
            string parameter = (argc > 4) ? argv[4] : "";
            processCommandLine1(mode, algorithm, fileName, parameter);
        }
        else if (argc == 6) {
            string algorithm = argv[2];
            int size = stoi(argv[3]);
            string order = argv[4];
            string parameter = (argc > 5) ? argv[5] : "";
            processCommandLine2(mode, algorithm, size, order, parameter);
        }
        else {
            string algorithm = argv[2];
            int size = stoi(argv[3]);
            string parameter = (argc > 4) ? argv[4] : "";
            processCommandLine3(mode, algorithm, size, parameter);
        }
    }

    else if (mode == "-c") {
        if (argc == 5) {
            string algorithm1 = argv[2];
            string algorithm2 = argv[3];
            string fileName = (argc > 4) ? argv[4] : "";
            processCommandLine4(mode, algorithm1, algorithm2, fileName);
        }

        else if (argc == 6) {
            string algorithm1 = argv[2];
            string algorithm2 = argv[3];
            int size = stoi(argv[4]);
            string order = (argc > 5) ? argv[5] : "";
            processCommandLine5(mode, algorithm1, algorithm2, size, order);
        }
    }

    else {
        cout << "Invalid mode!. Use -a or -c for algorithm mode." << endl;
    }
    return 0;
}