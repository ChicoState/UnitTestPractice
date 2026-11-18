/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_password_pass)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AbcdEFG");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_password_fail)
{
	Password my_password;
	int actual = !my_password.has_mixed_case("ABCDEFG");
	ASSERT_EQ(1, actual);
}