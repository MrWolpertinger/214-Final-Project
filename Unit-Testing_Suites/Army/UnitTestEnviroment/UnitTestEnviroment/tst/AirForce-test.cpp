#include "gtest/gtest.h"
#include "AirForce.h"

TEST(AirForceTest, test1) {
    //arrange
    AirForce *a = new AirForce(2,1,100);
    //act
    //assert
    EXPECT_EQ (a->getHP(),  200);
    EXPECT_EQ (a->getDMG(), 100);
    a->incHP(20);
    EXPECT_EQ (a->getHP(),  240);
    a->decHP(70);
    EXPECT_EQ (a->getDMG(), 50);
}