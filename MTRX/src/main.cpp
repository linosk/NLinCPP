#include "mtrx.hpp"
//tmp
#include <iostream>
int main(void){

    // MTRX A(2,3,"A");
    // A.fillMatrix(1);
    // MTRX B(2,3,"B");
    // B.fillMatrix(2);
    // MTRX C;
    // C.addMatrices(A,B,"C");

    MTRX A(1,3,"A");
    A.fillMatrix(2);
    MTRX B(3,2,"B");
    B.fillMatrix(6);
    MTRX C;
    C.dotProduct(A,B,"C");

    return 0;
}