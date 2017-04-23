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
TEST(romanTest, invString3){
	strcpy(entry, "IIV");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invString4){
	strcpy(entry, "IC");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invString5){
	strcpy(entry, "VV");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invString6){
	strcpy(entry, "VX");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invStringExt1){
	strcpy(entry, "VIX");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invStringExt2){
	strcpy(entry, "XXIXX");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, invStringExt3){
	strcpy(entry, "XLX");
	result=transf_roman(entry);
	EXPECT_EQ(-1, result);
}
TEST(romanTest, sixTest){
	strcpy(entry, "VI");
	result=transf_roman(entry);
	EXPECT_EQ(6, result);
}
TEST(romanTest, fourTest){
	strcpy(entry, "IV");
	result=transf_roman(entry);
	EXPECT_EQ(4, result);
}
TEST(romanTest, oneTest){
	strcpy(entry, "CXI");
	result=transf_roman(entry);
	EXPECT_EQ(111, result);
}
TEST(romnTest, randTest){
	strcpy(entry, "MMCLXI");
	result=transf_roman(entry);
	EXPECT_EQ(2161, result);
	strcpy(entry, "MCMXII");
	result=transf_roman(entry);
	EXPECT_EQ(1912, result);
	strcpy(entry, "CDXLV");
	result=transf_roman(entry);
	EXPECT_EQ(445, result);
	strcpy(entry, "MCXXV");
	result=transf_roman(entry);
	EXPECT_EQ(1125, result);
	strcpy(entry, "LV");
	result=transf_roman(entry);
	EXPECT_EQ(55, result);
	strcpy(entry, "CMLXXVII");
	result=transf_roman(entry);
	EXPECT_EQ(977, result);
	strcpy(entry, "MMDXIII");
	result=transf_roman(entry);
	EXPECT_EQ(2513, result);
	strcpy(entry, "MDCI");
	result=transf_roman(entry);
	EXPECT_EQ(1601, result);
	strcpy(entry, "MCDVI");
	result=transf_roman(entry);
	EXPECT_EQ(1406, result);
	strcpy(entry, "CLVII");
	result=transf_roman(entry);
	EXPECT_EQ(157, result);
	strcpy(entry, "MMCLXXXVIII");
	result=transf_roman(entry);
	EXPECT_EQ(2188, result);
	strcpy(entry, "DCCLXX");
	result=transf_roman(entry);
	EXPECT_EQ(770, result);
	strcpy(entry, "MMCMX");
	result=transf_roman(entry);
	EXPECT_EQ(2910, result);
	strcpy(entry, "CCCV");
	result=transf_roman(entry);
	EXPECT_EQ(305, result);
	strcpy(entry, "MDCCXLV");
	result=transf_roman(entry);
	EXPECT_EQ(1745, result);
}

TEST(indexVectorTest, testI){
	strcpy(entry, "IVXLCDM");
	size=strlen(entry);
	indexator(entry, size, index_v);
	for(i=0; i<size; i++){
		EXPECT_EQ(index_v[i], i+1);
	}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}