/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

// one leading character
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

// tons of leading characters
TEST(PasswordTest, multiple_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAABBB");
	ASSERT_EQ(4, actual);
}

// no leading characters
TEST(PasswordTest, no_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABCD");
	ASSERT_EQ(1, actual);
}

// mixed case password
TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("AbCdEfG");
	ASSERT_EQ(1, actual);
}

// all upper case password
TEST(PasswordTest, all_upper_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEFG");
	ASSERT_EQ(false, actual);
}

// all lower case password
TEST(PasswordTest, all_lower_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdefg");
	ASSERT_EQ(false, actual);
}

// Passing password
TEST(PasswordTest, passing_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AbcdefG");
	ASSERT_EQ(true, actual);
}
