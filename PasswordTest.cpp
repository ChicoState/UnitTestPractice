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

TEST(PasswordTest, double_letter_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("aa");
  ASSERT_EQ(2, actual);
}


TEST(PasswordTest, upper_lower_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("wW");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}


TEST(PasswordTest, newline_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("\n");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, space_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("  ");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, number_password)
{
  Password my_password;
  int actual=my_password.count_leading_characters("1123");
  ASSERT_EQ(2, actual);
}


TEST(PasswordTest, has_upper_and_lower)
{
  Password obj;
  ASSERT_TRUE(obj.has_mixed_case("Aa"));
}

TEST(PasswordTest, has_upper)
{
  Password obj;
  ASSERT_FALSE(obj.has_mixed_case("AA"));
}

TEST(PasswordTest, has_lower)
{
  Password obj;
  ASSERT_FALSE(obj.has_mixed_case("aa"));
}

TEST(PasswordTest, has_number)
{
  Password obj;
  ASSERT_FALSE(obj.has_mixed_case("123"));
}
