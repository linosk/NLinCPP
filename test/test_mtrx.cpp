#include <gtest/gtest.h>

#include "mtrx.h"

TEST(TEST_mtrx,MTRX_Fill){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(1);

    EXPECT_TRUE(Compare(A,B));
}

TEST(TEST_mtrx,MTRX_Transpose){
    MTRX A(2,3);
    A.Matrix[0][0] = 0;
    A.Matrix[0][1] = 1;
    A.Matrix[0][2] = 2;
    A.Matrix[1][0] = 3;
    A.Matrix[1][1] = 4;
    A.Matrix[1][2] = 5;

    A.Transponse();

    MTRX B(3,2);
    B.Matrix[0][0] = 0;
    B.Matrix[0][1] = 3;
    B.Matrix[1][0] = 1;
    B.Matrix[1][1] = 4;
    B.Matrix[2][0] = 2;
    B.Matrix[2][1] = 5;

    EXPECT_TRUE(Compare(A,B));
}

TEST(TEST_mtrx,MTRX_Add){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(2);

    MTRX C(3,3);
    C.Fill(3);

    MTRX D = Add(A,B);

    EXPECT_TRUE(Compare(C,D));

}

TEST(TEST_mtrx,MTRX_Dot_product){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(2);

    MTRX C(3,3);
    C.Fill(6);

    MTRX D = Dot_product(A,B);

    EXPECT_TRUE(Compare(C,D));

}
