
#include <gtest/gtest.h>


#include "mtrx.h"
//- this include makes issues, it is linking issue
//#include "../src/mtrx.cpp"

//Add mssing tests

TEST(TEST_MTRX,MTRX_Fill){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(1);

    EXPECT_TRUE(Compare(A,B));
}

TEST(TEST_MTRX,MTRX_Get_size){

    MTRX A(1,2);

    Dimensions Dimensions = A.Get_size();

    EXPECT_EQ(1,Dimensions.Number_rows);
    EXPECT_EQ(2,Dimensions.Number_columns);
}

TEST(TEST_MTRX,MTRX_Resize){

    MTRX A(1,2);

    A.Resize(60000,768);

    Dimensions Dimensions = A.Get_size();

    EXPECT_EQ(60000,Dimensions.Number_rows);
    EXPECT_EQ(768,Dimensions.Number_columns);
}

TEST(TEST_MTRX,MTRX_Transpose){
    MTRX A(2,3);
    A.Matrix_proper[0][0] = 0;
    A.Matrix_proper[0][1] = 1;
    A.Matrix_proper[0][2] = 2;
    A.Matrix_proper[1][0] = 3;
    A.Matrix_proper[1][1] = 4;
    A.Matrix_proper[1][2] = 5;

	MTRX B = Transpose(A);

    MTRX C(3,2);
    C.Matrix_proper[0][0] = 0;
    C.Matrix_proper[0][1] = 3;
    C.Matrix_proper[1][0] = 1;
    C.Matrix_proper[1][1] = 4;
    C.Matrix_proper[2][0] = 2;
    C.Matrix_proper[2][1] = 5;

    EXPECT_TRUE(Compare(B,C));
}

TEST(TEST_MTRX,MTRX_Add){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(2);

    MTRX C(3,3);
    C.Fill(3);

    MTRX D = Add(A,B);

    EXPECT_TRUE(Compare(C,D));

}

TEST(TEST_MTRX,MTRX_Dot_product){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(2);

    MTRX C(3,3);
    C.Fill(6);

    MTRX D = Dot_product(A,B);

    EXPECT_TRUE(Compare(C,D));

}