/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

//empty string
TEST(PasswordTest, empty_string_test)
{
    Password my_password;
        int actual = my_password.count_leading_characters("");
        ASSERT_EQ(0,actual);
}

//single letter lowercase
TEST(PasswordTest, single_letter_lowercase)
{
    Password my_password;
        int actual = my_password.count_leading_characters("a");
        ASSERT_EQ(1,actual);
}

//single character number
TEST(PasswordTest, single_number_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("6");
        ASSERT_EQ(1,actual);
}

//single punctuation
TEST(PasswordTest, single_punctuation_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("?");
        ASSERT_EQ(1,actual);
}

//multiple leading letters
TEST(PasswordTest, multiple_leading_letters)
{
    Password my_password;
        int actual = my_password.count_leading_characters("bbc");
        ASSERT_EQ(2,actual);
}

//multiple leading numbers
TEST(PasswordTest, multiple_leading_numbers)
{
    Password my_password;
        int actual = my_password.count_leading_characters("111c");
        ASSERT_EQ(3,actual);
}

//multiple leading punctuation
TEST(PasswordTest, multiple_leading_punct)
{
    Password my_password;
        int actual = my_password.count_leading_characters("////0n");
        ASSERT_EQ(4,actual);
}

//multiple spaces
TEST(PasswordTest, multiple_spaces)
{
    Password my_password;
        int actual = my_password.count_leading_characters("   ");
        ASSERT_EQ(3,actual);
}

//upper then lower
TEST(PasswordTest, upper_then_lowercase)
{
    Password my_password;
        int actual = my_password.count_leading_characters("AAaa");
        ASSERT_EQ(2,actual);
}

//longer string of same
TEST(PasswordTest, multiple_same_character)
{
    Password my_password;
        int actual = my_password.count_leading_characters("aaaaaaaaaaaa");
        ASSERT_EQ(12,actual);
}

//null terminator test
TEST(PasswordTest, null_terminator_test)
{
    Password my_password;
        int actual = my_password.count_leading_characters("\0");
        ASSERT_EQ(0,actual);
}

TEST(PasswordTest, has_upper_and_lower){
	Password obj;
	ASSERT_TRUE(obj.has_mixed_case("Aa"));
}





