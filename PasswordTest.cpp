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

TEST(PasswordTest, one_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zz");
	ASSERT_EQ(1, actual);
}


TEST(PasswordTest, no_leading_characters)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ab");
  ASSERT_EQ(1, actual); // "ab" has only 1 leading character 'a'
}

TEST(PasswordTest, empty_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual); // empty string should return 0
}

TEST(PasswordTest, has_mixed_case_true)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("PassWord");
  ASSERT_TRUE(actual); // "Password" has both upper and lower case letters
}

TEST(PasswordTest, has_mixed_case_false)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("password");
  ASSERT_FALSE(actual); // "password" has only lower case letters

  actual = my_password.has_mixed_case("PASSWORD");
  ASSERT_FALSE(actual); // "PASSWORD" has only upper case letters
}
