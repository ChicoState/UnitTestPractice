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

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, letters_repeated_at_end)
{
	Password my_p;
	int count = my_p.count_leading_characters("ZZAABB");
	ASSERT_EQ(2,count);
}

TEST(PasswordTest, non_letter_password)
{
	Password test;
	int pass = test.count_leading_characters("__password");
	ASSERT_EQ(2,pass);
}

TEST(PasswordTest, upper_lower)
{
	Password test;
	int pass = test.count_leading_characters("Aabbcc");
	ASSERT_EQ(1,pass);
}

TEST(PasswordTest, no_pass)
{
	Password test;
	int pass = test.count_leading_characters("");
	ASSERT_EQ(1,pass);
}

TEST(PasswordTest, mixed_pass)
{
	Password test;
	int pass = test.count_leading_characters("Aabbcc");
	ASSERT_EQ(true,pass);
}

TEST(PasswordTest, all_lower)
{
	Password test;
	int pass = test.count_leading_characters("aaaaa");
	ASSERT_EQ(false,pass);
}

TEST(PasswordTest, all_upper)
{
	Password test;
	int pass = test.count_leading_characters("AAAA");
	ASSERT_EQ(false,pass);
}

TEST(PasswordTest, special_mix)
{
	Password test;
	int pass = test.count_leading_characters("#1Aa");
	ASSERT_EQ(true,pass);
}
