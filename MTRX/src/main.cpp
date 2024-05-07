#include "mtrx.hpp"
//tmp
#include <iostream>
int main(void){

    MTRX A(2,3,"A");
    A.fillMatrix(1);

    MTRX B(2,3,"B");
    B.fillMatrix(2);
    
    MTRX C;
    C.addMatrices(A,B,"C");

    return 0;
}