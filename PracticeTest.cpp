/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"

class PracticeTest : public ::testing::Test
{
	int count_starting_repeats_test;

	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PracticeTest, smoke_test)
{
    ASSERT_TRUE(true);
}

// testing counting_starting_repeats() 

TEST(PracticeTest, CSR_xxx){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("xxx"), 3);
}

TEST(PracticeTest, CSR_avery){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("avery"), 1);
}

TEST(PracticeTest, CSR_nulls){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("\0\0\0"), 3);
}


TEST(PracticeTest, CSR_nums_repeating){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("222333444"), 3);
}

TEST(PracticeTest, CSR_nums_nonrepeating){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("12345"), 1);
}

TEST(PracticeTest, CSR_special_character_rep){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("$$$"), 3);
}

TEST(PracticeTest, CSR_special_character_nonrep){
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("$(*&#!$"), 1);
}

// test Practice.is_palindrome()

// pass: alphabetical palindrome 
TEST(PracticeTest, testKnownPal){
	Practice testObject;
	ASSERT_TRUE(testObject.isPalindrome("racecar"));
}
// pass : is not alphabetical palindrome
TEST(PracticeTest, testKnownFalsePal){
	Practice testObject;
	ASSERT_FALSE(testObject.isPalindrome("notapalindrome"));
}

// pass : numerical (string) palindrome
TEST(PracticeTest, numStringPal){
	Practice testObject;
	ASSERT_TRUE(testObject.isPalindrome("123321"));
}

TEST(PracticeTest, SD_test123){
	Practice testObject;
	int first = 1;
	int second = 2;
	int third = 3;

	testObject.sortDescending(first, second, third);

	ASSERT_EQ(first, 3);
	ASSERT_EQ(second, 2);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest, SD_TestNE123){
	Practice testObject;
	int first = 1;
	int second = 2;
	int third = 3;

	testObject.sortDescending(first, second, third);

	ASSERT_NE(first, 1);
	ASSERT_NE(second, 3);
	ASSERT_NE(third, 2);
}