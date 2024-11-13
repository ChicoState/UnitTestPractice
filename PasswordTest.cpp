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

TEST(PasswordTest, all_lowercase_password) {
    Password my_password;
    bool actual = my_password.has_mixed_case("password");
    ASSERT_EQ(false, actual);  //Should return false since there are no uppercase letters
}

TEST(PasswordTest, all_uppercase_password) {
    Password my_password;
    bool actual = my_password.has_mixed_case("PASSWORD");
    ASSERT_EQ(false, actual);  //Should return false since there are no lowercase letters
}

TEST(PasswordTest, mixed_case_password) {
    Password my_password;
    bool actual = my_password.has_mixed_case("PassWord");
    ASSERT_EQ(true, actual);  //Should return true since both uppercase and lowercase letters are present
}

TEST(PasswordTest, single_lowercase_character) {
    Password my_password;
    bool actual = my_password.has_mixed_case("a");
    ASSERT_EQ(false, actual);  //Should return false since there is only one lowercase letter
}

TEST(PasswordTest, single_uppercase_character) {
    Password my_password;
    bool actual = my_password.has_mixed_case("A");
    ASSERT_EQ(false, actual);  //Should return false since there is only one uppercase letter
}

TEST(PasswordTest, empty_string) {
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_EQ(false, actual);  //Should return false since the string is empty
}

TEST(PasswordTest, mixed_case_with_numbers_and_symbols) {
    Password my_password;
    bool actual = my_password.has_mixed_case("P@ssw0rd!");
    ASSERT_EQ(true, actual);  //Should return true since both uppercase and lowercase letters are present
}
