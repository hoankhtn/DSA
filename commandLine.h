#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <iostream>
using namespace std;

void processCommandLine1(string& mode, string& algorithm, const string& fileName, string& parameter);
void processCommandLine2(string& mode, string& algorithm, int &size, string& order, string& parameter);
void processCommandLine3(string& mode, string& algorithm, int& size, string& parameter);
void processCommandLine4(string& mode, string& algorithm1, string& algorithm2, const string& fileName);
void processCommandLine5(string& mode, string& algorithm1, string& algorithm2, int &size, string& order);

#endif