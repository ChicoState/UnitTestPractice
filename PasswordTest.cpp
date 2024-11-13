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

TEST(PasswordTest, double_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZzZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, special_characters_leading)
{
    Password my_password;
    int actual = my_password.count_leading_characters("###Hello");
    ASSERT_EQ(3, actual);
}


TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters(" ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, no_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("-@$@#$");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("GG");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("gg");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, upper_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Gg");
	ASSERT_EQ(true, actual);
}

