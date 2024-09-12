// NAME:
// LAB SECTION:
// LECTURE SECTION:
// 
// CS201L-Lab3.cpp : This project will complete the Lab3 (2-D Vectors) 
//

#include "Matrix.h"

int main() {
    cout << "Welcome to My 2-D Vector Processor!\n";

    ifstream inFile("dataValid.txt");
    if (!inFile.good()) {
        cout << "Error opening input file!\n";
        return -1;
    }

    string inputStr1, inputStr2;
	vector<vector<int> > v1, v2;

    bool valid1, valid2;

    // Loop through the file and read two lines at a time for each matrix set
    while (getline(inFile, inputStr1)) {
        if (getline(inFile, inputStr2)) {
            cout << "\n\nPROCESSING A SET OF MATRICES\n";

            // Clear vectors before processing new matrices
            v1.clear();
            v2.clear();

            // Process first matrix
            cout << "\n\tPROCESSING FIRST MATRIX\n";
            valid1 = verifyVector(v1, inputStr1);
            if (valid1) {
                printVector(v1);
                processVector(v1);
            } else {
                cout << "First matrix is invalid.\n";
            }

            // Process second matrix
            cout << "\n\tPROCESSING SECOND MATRIX\n";
            valid2 = verifyVector(v2, inputStr2);
            if (valid2) {
                printVector(v2);
                processVector(v2);
            } else {
                cout << "Second matrix is invalid.\n";
            }

            // If both matrices are valid, perform matrix operations
            if (valid1 && valid2) {
                cout << "\n\tPROCESSING BOTH MATRICES\n";
                addTwoMatrices(v1, v2);
                multiplyTwoMatrices(v1, v2);
            }
        } else {
            cout << "Unexpected end of file or missing second matrix.\n";
        }
    }

    inFile.close();
    return 0;
}
