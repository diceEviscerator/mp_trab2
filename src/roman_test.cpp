#include <limits.h>
#include "gtest/gtest.h"
#include "roman.h"

char entry[31]={"\0"};
int result;

TEST(romanTest, fail){
  result=transf_roman(entry);
  EXPECT_EQ(-1, result);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}