#include "mtrx.hpp"
//ALGORITHM FOR MATRIX PRODUCT
//Define matrix m x n
MTRX::MTRX(int m, int n) : rows(m), columns(n), logger("mtrx.log"){
    matrix.resize(rows,Vector(columns));

    logger.logInfo("Matrix created"); //maybe debug?
}

void MTRX::fillMatrix(int val){
    // for(auto i : matrix){
        // for(auto j : i){
            // j = val;
            //logger.
            // logger.logInfo("Value at " + to_string(i) + "s", val);
        // }
    // }
    for(int i=0;i<rows;i++){ // maybe auto loop?
        for(int j=0;j<columns;j++){
            matrix[i][j] = val;
            logger.logInfo("Value at ["+std::to_string(i)+"]["+std::to_string(j)+"] =",matrix[i][j]); // maybe debug?
        }
    }
}

//this should log
void MTRX::printMatrix(void){
    for(const auto i : matrix){
        for(const auto j : i){

        }
    }
} 