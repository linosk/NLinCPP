#include <gtest/gtest.h>

#include "mtrx.h"

TEST(TEST_mtrx,MTRX_Fill){

    MTRX A(3,3);
    A.Fill(1);

    MTRX B(3,3);
    B.Fill(1);

    EXPECT_TRUE(Compare(A,B));
}