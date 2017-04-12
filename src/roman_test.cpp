#include <limits.h>
#include "gtest/gtest.h"
#include "roman.h"

char entry[31];
int result;

TEST(romanTest, fail){
	entry=NULL;
	result=transf_roman((char*) entry);
	EXPECT_EQ(-1, result);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}