#include "mtrx.hpp"
//MAYBE DELETE DIMENSIONS, IT SEEMS OVERCOMPLICATED
MTRX::MTRX(int m, int n, std::string id) : dimensions({m,n}), name(id), logger("mtrx.log") {
    logger.enableDebug();
    logger.enableTimeLogging();
    matrix.resize(this->dimensions.rows,Vector(this->dimensions.columns)); //can be abstracted
    logger.logInfo({"Matrix",this->name,"created succesfully"});
    logger.logDebug({"#",this->name,"#"});
    logger.logDebug({"Number of rows:",std::to_string(this->dimensions.rows)});
    logger.logDebug({"Number of columns:",std::to_string(this->dimensions.columns)});
}

void MTRX::fillMatrix(int val){
    logger.logInfo({"Matrix",this->name,"filled with",std::to_string(val)});
    logger.logDebug({"#",this->name,"#"});
    for(int i=0;i<this->dimensions.rows;i++){ // maybe auto loop?
        for(int j=0;j<this->dimensions.columns;j++){
            this->matrix[i][j] = val;
            logger.logDebug({"Value at [",std::to_string(i),"][",std::to_string(j),"]:",std::to_string(this->matrix[i][j])});
        }
    }
}

MTRX::Dimensions MTRX::getDimensions(void){
    return this->dimensions;
}

bool MTRX::canBeAdded(const MTRX::Dimensions dimensionsFirst, const MTRX::Dimensions dimensionsSecond){
    if(dimensionsFirst.rows!=dimensionsSecond.rows||dimensionsFirst.columns!=dimensionsSecond.columns)
        return false;
    return true;
}

bool MTRX::canBeDotted(const MTRX::Dimensions dimensionsFirst, const MTRX::Dimensions dimensionsSecond){
    if(dimensionsFirst.columns!=dimensionsSecond.rows)
        return false;
    return true;
}

bool MTRX::addMatrices(const MTRX A, const MTRX B, const std::string id){
    if(canBeAdded(A.dimensions,B.dimensions)){

        //this->MTRX(A.dimensions.rows,A.dimensions.rows);
        
        this->matrix.resize(A.dimensions.rows,Vector(A.dimensions.columns)); // THIS SEEM redundant
        this->dimensions = A.dimensions; // THIS SEEM redundant
        this->name = id;

        logger.logInfo({"Matrix",this->name,"reshaped for addition"});
        logger.logDebug({"#",this->name,"#"});
        logger.logDebug({"Number of rows:",std::to_string(this->dimensions.rows)});
        logger.logDebug({"Number of columns:",std::to_string(this->dimensions.columns)});

        for(int i=0;i<this->dimensions.rows;i++){
            for(int j=0;j<this->dimensions.columns;j++){
                this->matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
                logger.logDebug({"Value at [",std::to_string(i),"][",std::to_string(j),"]:",std::to_string(this->matrix[i][j])});
            }
        }

    }
    return false;
}

bool dotProduct(MTRX A, MTRX B);


//ALGORITHM FOR MATRIX PRODUCT