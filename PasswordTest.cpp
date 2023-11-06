/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest:public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

//set your state
//invoke unit
//assert expected outcome
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
/*
TEST(PasswordTest, empty)
{
Password pass;
ASSERT_EQ(0,pass.count_leading_characters(""));
}*/
TEST(PasswordTest,string_with_upper_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("TTTTTT");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest,string_with_lower_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("ttttttt");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest,valid_string){
	Password my_password;
	bool actual = my_password.has_mixed_case("tTtTtTTttttttttttt");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest,first_or_last_char){
	Password my_password;
	bool actual = my_password.has_mixed_case("TtttttttttT");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest,first_or_last_char_vice_versa){
	Password my_password;
	bool actual = my_password.has_mixed_case("tTTTTTTTTTTTt");
	ASSERT_EQ(true,actual);
}
