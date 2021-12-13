/**
 * @file Matrix.h
 * @author Smit Modi(sjmodi1997.sm@gmail.com)
 * @brief defination of Matrix class
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<int>> matrix;
public:
    // Constructor
    Matrix(vector<vector<int>> matrix);
    
    // Main Functionalities
    vector<vector<int>> transpose();
    vector<vector<int>> multiply(vector<vector<int>> otherMatrix);

    // helper function
    void printMatrix();
    vector<vector<int>> getVector();
    static bool isValidDimentionsForMatrixMultiply(int rows1, int cols1, int rows2, int cols2); // static because it can be use without matrix object
};
