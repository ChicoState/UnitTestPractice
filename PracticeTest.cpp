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
        void sortDescending(int & first, int & second, int & third);
        bool isPalindrome(string input);
        int count_starting_repeats(string word);
};

TEST(PracticeTest, smoke_test)
{
    ASSERT_TRUE(true);
}

TEST(PracticeTest, countStartingRepeatsTest1) {
    Practice testObj;
    ASSERT_EQ(testObj.count_starting_repeats("zzzZzzzzz"), 3);
}

TEST(PracticeTest, countStartingRepeatsTest2) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("ppppppppppp"), 11);
}

TEST(PracticeTest, countStartingRepeatsTest3) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats(""), 0);
}

TEST(PracticeTest, isPalindromeTest1) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("racecar"));
}

TEST(PracticeTest, isPalindromeTest2) {
Practice testObj;
ASSERT_TRUE(!testObj.isPalindrome("ab"));
}

TEST(PracticeTest, isPalindromeTest3) {
Practice testObj;
ASSERT_TRUE(!testObj.isPalindrome("abcdabcd"));
}

TEST(PracticeTest, isPalindromeTest4) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("\0\n.abcd1234🥴4321dcba.\n\0"));
}


TEST(PracticeTest, sortDescendingTest1) {
Practice testObj;
int a = 1, b = 2, c = 3;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, sortDescendingTest2) {
Practice testObj;
int a = 3, b = 2, c = 1;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, sortDescendingTest3) {
Practice testObj;
int a = 2, b = 3, c = 1;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

