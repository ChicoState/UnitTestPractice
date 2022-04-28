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

// count_starting_repeats test PASSES
TEST(PracticeTest, zzzrepeats)
{
    Practice testObject;
    ASSERT_EQ( testObject.count_starting_repeats("zzz"), 2);
}

// count_starting_repeats test FAILS
TEST(PracticeTest, norepeat)
{
    Practice testObject;
    ASSERT_EQ( testObject.count_starting_repeats("hello"), 0);
}

// count_starting_repeats test EMPTY
TEST(PracticeTest, emptystring)
{
    Practice testObject;
    ASSERT_EQ( testObject.count_starting_repeats(""), 0);
}

// sortDescending test FAILS
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

// sortDescending test PASSES
TEST(PracticeTest, repeats_descending_true)
{
    Practice testObject;
    int a = 3;
    int b = 3;
    int c = 3;
    testObject.sortDescending(a, b, c);
    ASSERT_EQ(a, 3);
    ASSERT_EQ(b, 3);
    ASSERT_EQ(c, 3);
}

// isPalindrome test PASSES
TEST(PracticeTest, isPalindrome)
{
    Practice testObject;
    string palin = "tacocat";
    bool isPalin = testObject.isPalindrome(palin);
    ASSERT_EQ(isPalin, true);
}

// isPalindrome test FAILS
TEST(PracticeTest, isNotPalindrome)
{
    Practice testObject;
    string palin = "vitamin";
    bool isPalin = testObject.isPalindrome(palin);
    ASSERT_EQ(isPalin, true);
}

// isPalindrome test EMPTY
TEST(PracticeTest, isEmptyPalindrome)
{
    Practice testObject;
    string palin = "";
    bool isPalin = testObject.isPalindrome(palin);
    ASSERT_EQ(isPalin, true);
}

// allnighter doesn't find any all nighters
TEST(PracticeTest, noallnighter)
{
    Practice testObject;
    int sleep_hours[7] = {7};
    bool no_sleep = false;
    if(testObject.allnighter(sleep_hours)){
        no_sleep = true;
    }
    ASSERT_EQ(no_sleep, true);
}

// allnighter finds an all nighter
TEST(PracticeTest, allnighter)
{
    Practice testObject;
    int sleep_hours[7] = {0};
    bool no_sleep = false;
    if(testObject.allnighter(sleep_hours)){
        no_sleep = true;
    }
    ASSERT_EQ(no_sleep, true);
}