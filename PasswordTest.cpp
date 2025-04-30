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

TEST(PasswordTest, two_sameletter_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, four_sameletter_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaab");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, one_sameletter_differentletters_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abcdefa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_two_sameletter_withsamebutcapital_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaAAaa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, spacesleading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   test");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, two_numericcharacters_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("11aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, alternatingcharacters_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("xyxyxyx");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, emptystring_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, allupper_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("HELLO");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, singleupper_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("H");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, singlelower_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("h");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, digitstring_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("123");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, digits_and_upperandlower_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Hello123");
	ASSERT_EQ(true, actual);
}


/*TEST(PasswordTest, empty_string_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);


*/

/*TEST(PasswordTest, emptystring_mixedstring)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
*/