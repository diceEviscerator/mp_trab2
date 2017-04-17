#include <limits.h>
#include "gtest/gtest.h"
#include "roman.h"

char entry[31]={"\0"};
int result;

TEST(romanTest, empty){
  result=transf_roman(entry);
  EXPECT_EQ(-1, result);

}
TEST(romanTest, invString){
	strcpy(entry, "aaa");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, threeTest){
	strcpy(entry, "III");
	result=transf_roman(entry);
	EXPECT_EQ(3, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}