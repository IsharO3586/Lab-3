#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Function declarations
bool verifyVector(vector<vector<int> >& vec1, string inputStr);
void processVector(vector<vector<int> >& vec1);
void addTwoMatrices(vector<vector<int> >& vec1, vector<vector<int> >& vec2);
void multiplyTwoMatrices(vector<vector<int> >& vec1, vector<vector<int> >& vec2);
void printVector(const vector<vector<int> >& vec1);
