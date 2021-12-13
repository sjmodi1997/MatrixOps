#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

/**
 * @brief A custom function to check if two vector of vector are same or not 
 * 
 * @param v1 
 * @param v2 
 * @return true 
 * @return false 
 */
bool areSameMatrix(vector<vector<int>> v1, vector<vector<int>> v2){
    int rows1 = v1.size();
    int rows2 = v2.size();
    if(rows1 == 0 && rows2 == 0)
        return true;
    if(rows1 == 0 || rows2 == 0)
        return false;
    if(rows1 != rows2)
        return false;
    
    int cols1 = v1[0].size();
    int cols2 = v2[0].size();

    if(cols1 != cols2)
        return false;
    
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            if(v1[i][j] != v2[i][j]){
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // Testcase 1
    Matrix m1({{1, 2},{3, 4}});    
    Matrix m2 = m1.transpose(); 
    areSameMatrix(m2.getVector(), {{1,3},{2,4}}) ? printf("Test case 1 passed!!") : printf("Test case 1 failed!!");
    printf("\n");
    // Testcase 2
    Matrix m3({{4, 5}});    
    Matrix m4 = m3.multiply({{1, 2, 3}, {4, 5, 6}}); 
    areSameMatrix(m4.getVector(), {{24, 33, 42}}) ? printf("Test case 2 passed!!") : printf("Test case 2 failed!!");
    printf("\n");
    // Testcase 3
    bool testCase3 = false;
    try{
        Matrix m5({});
    }
    catch (exception e){
        testCase3 = true;
    }
    testCase3 ? printf("Test case 3 passed!!") : printf("Test case 3 failed!!");
    printf("\n");
    // Testcase 4
    bool testCase4 = false;
    try{
        Matrix m6({{2, 1}, {7, 8}});
        Matrix m7 = m6.multiply({{1}});
    }catch(exception e){
        testCase4 = true;
    }
    testCase4 ? printf("Test case 4 passed!!") : printf("Test case 4 failed!!");
    printf("\n");
    return 0;
}
