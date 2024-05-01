#include "mtrx.hpp"
//ALGORITHM FOR MATRIX PRODUCT
//Define matrix m x n
MTRX::MTRX(int m, int n) : rows(m), columns(n){
    matrix.resize(rows,Vector(columns));
}
//this should log
void MTRX::printMatrix(void){
    for(auto i : matrix){
        for(auto j : i){

        }
    }
} 