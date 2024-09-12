#include "Matrix.h"

// Function to verify vector
bool verifyVector(vector<vector<int> >& vec1, string inputStr) {
    stringstream ss(inputStr);
    int rows, cols;
    ss >> rows >> cols;

    // Validate rows and columns (between 1 and 5)
    if (rows < 1 || rows > 5 || cols < 1 || cols > 5) {
        cout << "Invalid number of rows or columns.\n";
        return false;
    }

    vec1.resize(rows, vector<int>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            int val;
            ss >> val;
            // Validate 0 or 1 values
            if (val != 0 && val != 1) {
                cout << "Invalid matrix value. Must be 0 or 1.\n";
                return false;
            }
            vec1[i][j] = val;
        }
    }
    return true;
}

// Function to print the vector
void printVector(const vector<vector<int> >& vec1) {
    for (const auto& row : vec1) {
        for (const auto& val : row) {
            cout << setw(2) << val;
        }
        cout << endl;
    }
}

// Function to check if a matrix is reflexive or symmetric
void processVector(vector<vector<int> >& vec1) {
    if (vec1.size() != vec1[0].size()) {
        cout << "Reflexive, symmetric, or transitive properties: Matrix must be square.\n";
        return;
    }

    bool reflexive = true, symmetric = true;
    size_t n = vec1.size();

    // Check reflexive (diagonal elements are 1)
    for (size_t i = 0; i < n; ++i) {
        if (vec1[i][i] != 1) {
            reflexive = false;
        }
    }

    // Check symmetric (elements across diagonal are equal)
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (vec1[i][j] != vec1[j][i]) {
                symmetric = false;
            }
        }
    }

    if (reflexive)
        cout << "The matrix is reflexive.\n";
    else
        cout << "The matrix is not reflexive.\n";

    if (symmetric)
        cout << "The matrix is symmetric.\n";
    else
        cout << "The matrix is not symmetric.\n";
}

// Function to add two matrices
void addTwoMatrices(vector<vector<int> >& vec1, vector<vector<int> >& vec2) {
    if (vec1.size() != vec2.size() || vec1[0].size() != vec2[0].size()) {
        cout << "Addition: Matrices must be the same size to add.\n";
        return;
    }

    size_t rows = vec1.size(), cols = vec1[0].size();
    vector<vector<int> > result(rows, vector<int>(cols));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = vec1[i][j] + vec2[i][j];
        }
    }

    cout << "Matrices Added:\n";
    printVector(result);
}

// Function to multiply two matrices
void multiplyTwoMatrices(vector<vector<int> >& vec1, vector<vector<int> >& vec2) {
    if (vec1[0].size() != vec2.size()) {
        cout << "Multiplication: Number of columns in the first matrix is not equal to the number of rows in the second matrix.\n";
        return;
    }

    size_t rows1 = vec1.size(), cols1 = vec1[0].size();
    size_t cols2 = vec2[0].size();
    vector<vector<int> > result(rows1, vector<int>(cols2, 0));

    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            for (size_t k = 0; k < cols1; ++k) {
                result[i][j] += vec1[i][k] * vec2[k][j];
            }
        }
    }

    cout << "Matrices Multiplied:\n";
    printVector(result);
}

