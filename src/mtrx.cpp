#include "mtrx.h"

MTRX::MTRX(int M, int N) : Rows(M), Columns(N){
    Matrix_proper.resize(Rows,Vector(Columns));
}

void MTRX::Print(){
    for(auto i : Matrix_proper){
		for(auto j : i){
			std::cout<<j;
		}
	    std::cout<<std::endl;
	}
}

void MTRX::Fill(int Number){
    for(auto& i : Matrix_proper){
        for (auto& j : i){
            j = Number;
        }
    }
}

Dimensions MTRX::Get_size(){

    Dimensions Dimensions;
    Dimensions.Number_rows = Rows;
    Dimensions.Number_columns = Columns;

    return Dimensions;
}

void MTRX::Resize(int New_rows, int New_columns){
    
    Matrix_proper.resize(New_rows);
    for (int i = 0 ;i<New_rows;i++){
        Matrix_proper[i].resize(New_columns);
    }

    Rows=New_rows;
    Columns=New_columns;
}

int MTRX::Read_from_file(std::string Path){

    uint8_t Data_offset = 4*sizeof(uint8_t);

    if(std::filesystem::exists(Path)){
        std::ifstream File(Path);
        //This has to be checked
        File.seekg(Data_offset);
        int Size = File.tellg();
        std::cout<<Size<<std::endl;
        File.seekg(std::ios::end);
        Size = File.tellg();
        std::cout<<Size<<std::endl;
        File.close();
        return 0;
    }
    return -1;
}

bool Compare(MTRX A, MTRX B){
    if((A.Rows != B.Rows) || (A.Columns != B.Columns)){
		throw std::invalid_argument("Matrices's dimensions did not match.");
	}

    for(int i=0;i<A.Rows;i++){
        for(int j=0;j<A.Columns;j++){
            if(A.Matrix_proper[i][j]!=B.Matrix_proper[i][j]){
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
            C.Matrix_proper[i][j] = A.Matrix_proper[i][j] + B.Matrix_proper[i][j];
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
                C.Matrix_proper[i][j] = C.Matrix_proper[i][j] + A.Matrix_proper[i][k] * B.Matrix_proper[k][j];
            }
        }
    }

    return C;    
}

MTRX Transpose(MTRX A){
    MTRX B(A.Columns,A.Rows);
    B.Fill(0);

    for(int i=0;i<B.Rows;i++){
        for(int j=0;j<B.Columns;j++){
            B.Matrix_proper[i][j] = A.Matrix_proper[j][i];
        }
    }

    return B;
}