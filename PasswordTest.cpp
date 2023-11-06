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
TEST(PasswordTest,letters_repeated_at_end ){
	Password my_password;
	int actual = (3 - my_password.count_leading_characters("Zoo"));
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest,empty_password){
	Password my_password;
	int length = my_password.count_leading_characters("");
	ASSERT_EQ(0,length);
}
TEST(PasswordTest,empty_password2){
	Password my_password;
	int length = my_password.has_Mixed_Case("");
	ASSERT_EQ(0,length);
}
TEST(PasswordTest,single_character){
	Password my_password;
	int length = my_password.has_Mixed_Case("h");
	ASSERT_EQ(1,length);
}
