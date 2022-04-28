/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PracticeTest, smoke_test) {
    ASSERT_TRUE(true);
}

TEST(PracticeTest, palindrome) {
	Practice testObject;
	ASSERT_EQ(testObject.isPalindrome("tacocat"), true);
}

TEST(PracticeTest, notPalindrome) {
	Practice testObject;
	ASSERT_EQ(testObject.isPalindrome("tacocatt"), false);
}

TEST(PracticeTest, emptyPalindrome) {
	Practice testObject;
	ASSERT_EQ(testObject.isPalindrome(""), false);
}

TEST(PracticeTest, symbolPalindrome) {
	Practice testObject;
	ASSERT_EQ(testObject.isPalindrome("&a&"), true);
}

TEST(PracticeTest,repeats) {
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("ooonly"), 2);
}

TEST(PracticeTest,noRepeats) {
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats("only"), 0);
}

TEST(PracticeTest,emptyRepeats) {
	Practice testObject;
	ASSERT_EQ(testObject.count_starting_repeats(""), 0);
}

TEST(PracticeTest,descending153) {	//test each combination
	Practice testObject;
	int first= 1;
	int second= 5;
	int third= 3;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descendingRepeats) {	//test each combination
	Practice testObject;
	int first= 1;
	int second= 1;
	int third= 2;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 2);
	ASSERT_EQ(second, 1);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descendingAscending) {	//test each combination
	Practice testObject;
	int first= 1;
	int second= 3;
	int third= 5;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descending315) {	//test each combination
	Practice testObject;
	int first= 3;
	int second= 1;
	int third= 5;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descending351) {	//test each combination
	Practice testObject;
	int first= 3;
	int second= 5;
	int third= 1;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descending513) {	//test each combination
	Practice testObject;
	int first= 5;
	int second= 1;
	int third= 3;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest,descendingDescending) {	//test each combination
	Practice testObject;
	int first= 5;
	int second= 3;
	int third= 1;
	testObject.sortDescending(first, second, third);
	ASSERT_EQ(first, 5);
	ASSERT_EQ(second, 3);
	ASSERT_EQ(third, 1);
}

TEST(PracticeTest, noNighter) {
	Practice testObject;
	int array[7] = {1,2,3,4,5,6,7};
	int* pointer = nullptr;
	int* none = testObject.allnighter(array);
	ASSERT_EQ(none, pointer);
}

TEST(PracticeTest, firstNighter) {
	Practice testObject;
	int array[7] = {0,0,3,4,5,6,7};
	int* pointer = &array[0];
	ASSERT_EQ(testObject.allnighter(array), pointer);
}

TEST(PracticeTest, lastNighter) {
	Practice testObject;
	int array[7] = {1,2,3,4,5,6,0};
	int* pointer = &array[6];
	ASSERT_EQ(testObject.allnighter(array), pointer);
}

TEST(PracticeTest, emptyNighter) {
	Practice testObject;
	int array[7];
	int* pointer = nullptr;
	int* none = testObject.allnighter(array);
	ASSERT_EQ(none, pointer);
}