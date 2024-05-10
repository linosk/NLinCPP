#include <gtest/gtest.h>

#include "mtrx.hpp"

TEST(TEST_MTRX,canBeAdded_True){
   
    MTRX A(2,2);

    MTRX B(2,2);

    EXPECT_TRUE(A.canBeAdded(A.dimensions,B.dimensions));

}

TEST(TEST_MTRX,canBeAdded_False){
    
    MTRX A(1,1);

    MTRX B(3,3);

    EXPECT_FALSE(A.canBeAdded(A.dimensions,B.dimensions));
}

TEST(TEST_MTRX,canBeDotted_True){
   
    MTRX A(1,3);

    MTRX B(3,2);

    EXPECT_TRUE(A.canBeDotted(A.dimensions,B.dimensions));

}

TEST(TEST_MTRX,canBeDotted_False){
    
    MTRX A(1,3);

    MTRX B(1,3);

    EXPECT_FALSE(A.canBeDotted(A.dimensions,B.dimensions));
}

//FINISH