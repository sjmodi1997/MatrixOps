/**
 * @file Matrix.cpp
 * @author Smit Modi (sjmodi1997.sm@gmail.com)
 * @brief Main implementation class for matrix
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;
/**
 * @brief Init Matrix
 * 
 * @param inputMatrix 
 * @return Matrix 
 */
Matrix :: Matrix(vector<vector<int>> inputMatrix){
    this->rows = inputMatrix.size();
    if(this->rows == 0){
        throw std :: invalid_argument("Empty Matrix can't be initailized!");
    }
    this->cols = inputMatrix[0].size();
    this->matrix = inputMatrix;
}

/**
 * @brief Transpose of Matrix
 * 
 * @return vector<vector<int>> 
 */
vector<vector<int>> Matrix :: transpose(){
    vector<vector<int>> transposeMatrix(this->cols, vector<int>(this->rows));
    
    for(int i=0; i < this->rows ; i++){
        for(int j=0; j < this->cols; j++){
            transposeMatrix[i][j] = this->matrix[j][i];
        }
    }

    return transposeMatrix;
}
/**
 * @brief Multiply with other Matrix
 * 
 * @param otherMatrix 
 * @return vector<vector<int>> 
 */
vector<vector<int>> Matrix :: multiply (vector<vector<int>> otherMatrix){
    int numOfRowsMatrix1 = this->rows;
    int numOfColsMatrix1 = this->cols;

    int numOfRowsMatrix2 = otherMatrix.size();
    if(numOfRowsMatrix2 == 0){
        throw invalid_argument("Empty Matrix can't be Multiply with other matrix!");
    }
    int numOfColsMatrix2 = otherMatrix[0].size();
    vector<vector<int>> resultMatrix; 
    printf("Matrix dimentions :: %d %d %d %d\n", numOfRowsMatrix1, numOfColsMatrix1, numOfRowsMatrix2, numOfColsMatrix2);
    if(!isValidDimentionsForMatrixMultiply(numOfRowsMatrix1, numOfColsMatrix1, numOfRowsMatrix2, numOfColsMatrix2)){
        throw invalid_argument("Given Matrices are Incompitable for Multiplication");
    }
    resultMatrix.resize(numOfRowsMatrix1, vector<int> (numOfColsMatrix2));

    for(int j=0; j < numOfColsMatrix2; j++){
        for(int k=0; k < numOfColsMatrix1; k++){
            for(int i=0; i < numOfRowsMatrix1; i++){
                if(resultMatrix[i][j] + (this->matrix[i][k] * otherMatrix[k][j]) > INT32_MAX){
                    throw out_of_range("Values in Matrices are such that Result Matrix cna be out of range!");
                }
                resultMatrix[i][j] += this->matrix[i][k] * otherMatrix[k][j];
            }
        }
    }    

    return resultMatrix;
}
/**
 * @brief check if dimentions of matrices are valid for Matrix Multiply
 * 
 * @param rows1 
 * @param cols1 
 * @param rows2 
 * @param cols2 
 * @return true 
 * @return false 
 */
bool Matrix :: isValidDimentionsForMatrixMultiply(int rows1, int cols1, int rows2, int cols2){
    return cols1 == rows2; 
}
/**
 * @brief print the matrix
 * 
 */
void Matrix :: printMatrix(){

    for(int i=0; i < this->rows ; i++){
        for(int j=0; j < this->cols; j++){
            printf("%d ", this->matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Get the Matrix in Vector Form
 * 
 */
vector<vector<int>> Matrix :: getVector(){
    return this->matrix;
}




