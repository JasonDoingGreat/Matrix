//
//  main.cpp
//  Matrix
//
//  Created by Zezhou Li on 2/1/17.
//  Copyright © 2017 Zezhou Li. All rights reserved.
//

#include <iostream>
#include "Matrix.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> a = {{0,1},{2,3}};
    Matrix<int> m(2, 2);
    m = Matrix<int>(a);
    vector<int> l = m.getColumn(0);
    for (int i = 0; i<l.size(); ++i) {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << m;
    return 0;
}
