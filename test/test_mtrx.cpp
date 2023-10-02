#include <gtest/gtest.h>

#include "mtrx.h"

TEST(TEST_mtrx,MTRX_Fill){

    MTRX A(1,1);
    A.Matrix[1][1] = 1;

    MTRX B(1,1);
    B.Matrix[1][1] = 1;

    EXPECT_TRUE(Compare(A,B));
}