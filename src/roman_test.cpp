#include <limits.h>
#include "gtest/gtest.h"
#include "roman.h"

char entry[31]={"\0"};
int result, i, size, index_v[31];


TEST(romanTest, empty){
  result=transf_roman(entry);
  EXPECT_EQ(-1, result);

}
TEST(romanTest, invString){
	strcpy(entry, "aaa");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invString2){
	strcpy(entry, "IIII");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, threeTest){
	strcpy(entry, "III");
	result=transf_roman(entry);
	EXPECT_EQ(3, result);
}

TEST(indexVectorTest, testI){
	strcpy(entry, "IVXLCDM");
	size=strlen(entry);
	index_vector(entry, size, index_v);
	for(i=0; i<size; i++){
		EXPECT_EQ(index_v[i], i+1);
	}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}