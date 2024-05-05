#include "mtrx.hpp"

MTRX::MTRX(int m, int n, std::string id) : rows(m), columns(n), name(id), logger("mtrx.log") {
    logger.enableDebug();
    logger.enableTimeLogging();
    matrix.resize(rows,Vector(columns));
    this->dimensions.rows = this->rows;
    this->dimensions.columns = this->columns;
    logger.logInfo({"Matrix",this->name,"created succesfully"});
    logger.logDebug({"#",this->name,"#"});
    logger.logDebug({"Number of rows:",std::to_string(this->dimensions.rows)});
    logger.logDebug({"Number of columns:",std::to_string(this->dimensions.columns)});
}

/*
//Define matrix m x n
MTRX::MTRX(int m, int n) : rows(m), columns(n), logger("mtrx.log"){
    logger.enableDebug(); //does not has to be enabled from this level
    logger.enableTimeLogging();
    matrix.resize(rows,Vector(columns));
    this->dimensions.rows = this->rows;
    this->dimensions.columns = this->columns;
    logger.logInfo("Matrix created succesfully");
    logger.logDebug("Number of rows:",this->dimensions.rows);
    logger.logDebug("Number of columns:",this->dimensions.rows);
}
//Define matrix m x n and give it a name
MTRX::MTRX(int m, int n, std::string name) : rows(m), columns(n), name(name), logger("mtrx.log"){
    //logger.enableDebug();  //does not has to be enabled from this level
    matrix.resize(rows,Vector(columns));
    this->dimensions.rows = this->rows;
    this->dimensions.columns = this->columns;
    logger.logInfo("Matrix "+this->name+" created succesfully");
    logger.logDebug("#"+this->name+"#");
    logger.logDebug("Number of rows:",this->dimensions.rows);
    logger.logDebug("Number of columns:",this->dimensions.rows);
}

void MTRX::loopMatrix(void){
    logger.logInfo("Matrix "+this->name+" looped");
    logger.logDebug("#"+this->name+"#");
    for(int i=0;i<rows;i++){ // maybe auto loop?
        for(int j=0;j<columns;j++){
            logger.logDebug("Value at ["+std::to_string(i)+"]["+std::to_string(j)+"]:",matrix[i][j]);
        }
    }
}

void MTRX::fillMatrix(int val){
    logger.logInfo("Matrix "+this->name+" filled with",val);
    logger.logDebug("#"+this->name+"#");
    for(int i=0;i<rows;i++){ // maybe auto loop?
        for(int j=0;j<columns;j++){
            matrix[i][j] = val;
            logger.logDebug("Value at ["+std::to_string(i)+"]["+std::to_string(j)+"]:",matrix[i][j]);
        }
    }
}

MTRX::Dimensions MTRX::getDimensions(void){
    return this->dimensions;
}

bool MTRX::canBeAdded(MTRX::Dimensions dimensionsFirst, MTRX::Dimensions dimensionsSecond){
    if(dimensionsFirst.rows!=dimensionsSecond.rows||dimensionsFirst.columns!=dimensionsSecond.columns)
        return false;
    return true;
}

bool MTRX::canBeDotted(MTRX::Dimensions dimensionsFirst, MTRX::Dimensions dimensionsSecond){
    if(dimensionsFirst.columns!=dimensionsSecond.rows){
        return false;
    }
    return true;
}
*/
//ALGORITHM FOR MATRIX PRODUCT