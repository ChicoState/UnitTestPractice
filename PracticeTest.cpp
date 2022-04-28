/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"
#include <string>

class PracticeTest : public ::testing::Test
{
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

TEST(PracticeTest, zzzrepeats)
{
    Practice testObject;
    ASSERT_EQ( testObject.count_starting_repeats("zzz"), 3);
}

TEST(PracticeTest, descending_true)
{
    Practice testObject;
    int a = 1;
    int b = 2;
    int c = 3;
    testObject.sortDescending(a, b, c);
    ASSERT_EQ(a, 3);
    ASSERT_EQ(b, 2);
    ASSERT_EQ(c, 1);
}

TEST(PracticeTest, isPalindrome)
{
    Practice testObject;
    string palin = "tacocat";
    bool isPalin = testObject.isPalindrome(palin);
    ASSERT_EQ(isPalin, true);
}

TEST(PracticeTest, allnighter)
