//
//  Matrix.h
//  Matrix
//
//  Created by Zezhou Li on 2/1/17.
//  Copyright © 2017 Zezhou Li. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
public:
    vector<vector<T>> array;
    
public:
    Matrix(int rows, int cols) : array(rows) {
        for(auto &currentRow: array)
            currentRow.resize(cols);
    }
    
    Matrix(vector<vector<T>> copyVector) : array{ copyVector } {}
    
    Matrix(vector<vector<T>> && moveVector) : array{ std::move(moveVector) } {}
    
    const vector<T> & operator[] (int row) const
    { return array[row]; }
    
    vector<T> & operator[] (int row)
    { return array[row]; }
    
    friend ostream & operator << (ostream & output, const Matrix& m) {
        int row = m.numberOfRows();
        int col = m.numberOfCols();
        for (int i = 0; i<row; ++i) {
            for (int j = 0; j<col; ++j) {
                output << m.array[i][j] << ' ';
            }
            output << endl;
        }
        return output;
    }
    
    vector<T> getColumn(int col) {
        const int row = numberOfRows();
        vector<T> temp;
        for (int i = 0; i<row; ++i) {
            temp.push_back(array[i][col]);
        }
        return temp;
    }
    
    int numberOfRows() const
    { return (int)array.size(); }
    
    int numberOfCols() const
    { return numberOfRows() ? (int)array[0].size() : 0; }
    
};

#endif /* Matrix_h */
