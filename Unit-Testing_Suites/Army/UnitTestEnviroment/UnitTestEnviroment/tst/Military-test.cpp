#include "Military.h"
#include "gtest/gtest.h"

TEST(MilitaryTest, test1) {
    Military *M = new Military();
    M->add(new Navy(3,1,115));
    M->add(new AirForce(1,5,30));
    //arrange
    //act
    //assert
    EXPECT_EQ (M->getType(),  'M');
    EXPECT_EQ (M->getTotalDMG(), 265);
    EXPECT_EQ (M->getTotalHP(), 375);
}

TEST(MilitaryTest, test2) {
    Military *M = new Military();
    M->add(new Navy(3,1,115));
    M->add(new AirForce(1,5,30));
    M->add(new AirForce(1,3,35));
    //arrange
    //act
    //assert
    EXPECT_EQ (M->getType(),  'M');
    EXPECT_EQ (M->getTotalDMG(), 370);
    EXPECT_EQ (M->getTotalHP(), 410);
}