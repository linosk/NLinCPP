#include "mtrx.h"

MTRX::MTRX(int M, int N) : Rows(M), Columns(N), Matrix(M,std::vector<int>(N,0)){}

void MTRX::Print(){
    for(auto i : Matrix){
		for(auto j : i){
			std::cout<<j;
		}
	    std::cout<<std::endl;
	}
}

void MTRX::Fill(int Number){
    for(auto& i : Matrix){
        for (auto& j : i){
            j = Number;
        }
    }
}

bool Compare(MTRX A, MTRX B){
    if((A.Rows != B.Rows) || (A.Columns != B.Columns)){
		throw std::invalid_argument("Matrices's dimensions did not match.");
	}

    for(int i=0;i<A.Rows;i++){
        for(int j=0;j<A.Columns;j++){
            if(A.Matrix[i][j]!=B.Matrix[i][j]){
                return false;
            }
        }
    }

    return true;
}

MTRX Add(MTRX A, MTRX B){
    if((A.Rows != B.Rows) || (A.Columns != B.Columns)){
		throw std::invalid_argument("Matrices's dimensions did not match.");
	}

	MTRX C(A.Rows,B.Columns);

    for(int i=0;i<C.Rows;i++){
        for(int j=0;j<C.Columns;j++){
            C.Matrix[i][j] = A.Matrix[i][j] + B.Matrix[i][j];
        }
    }

	return C;
}

MTRX Dot_product(MTRX A, MTRX B){
    if(A.Columns != B.Rows){
		throw std::invalid_argument("Matrices's dimensions did not match.");
	}

    MTRX C(A.Rows,B.Columns);
    C.Fill(0);
    for(int i=0;i<A.Rows;i++){
        for (int j=0;j<B.Columns;j++){
            for(int k=0;k<B.Rows;k++){
                C.Matrix[i][j] = C.Matrix[i][j] + A.Matrix[i][k] * B.Matrix[k][j];
            }
        }
    }

    return C;    
}
