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

TEST(EmptyStringMixedCaseTest, empty_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(actual, false);
}

TEST(AllLowerCaseMixedCaseTest, all_lower_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaa");
	ASSERT_EQ(actual, false);
}

TEST(AllUpperCaseMixedCaseTest, all_upper_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAAA");
	ASSERT_EQ(actual, false);
}

TEST(MixedStringMixedCaseTest, mixed_case_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("aAaAaA");
	ASSERT_EQ(actual, true);
}

TEST(AllSpacesMixedCaseTest, all_spaces_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("      ");
	ASSERT_EQ(actual, false);
}

TEST(AllPunctuationMixedCaseTest, all_punctuation_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("!.,!\"?,;\",");
	ASSERT_EQ(actual, false);
}

TEST(KeyBoardMashingMixedCaseTest, all_punctuation_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("aeriubgarweogbasPAOEIRU GA	AOERIUG Apiuvr");
	ASSERT_EQ(actual, true);
}

TEST(SingleLetterMixedCaseTest, single_letter_string) {
	Password my_password;
	bool actual = my_password.has_mixed_case("B");
	ASSERT_EQ(actual, false);
}

TEST(LowerCaseLettersAndNumbersMixedCaseTest, lowercase_letters_and_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("12345ggggg");
	ASSERT_EQ(actual, false);
}

TEST(UpperCaseLettersAndNumbersMixedCaseTest, uppercase_letters_and_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("12345GGGGGG");
	ASSERT_EQ(actual, false);
}

TEST(UpperAndLowerCaseLettersAndNumbersMixedCaseTest, upper_and_lowercase_letters_and_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("1234PpPpllaefLLv4566arvIUAO");
	ASSERT_EQ(actual, true);
}

TEST(MixedCaseWithNumbersAndLettersAndPunctuation, mixed_upper_lower_letters_punctuation_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("1234PpPpl\"la(ef,!!!!LLv.4.5.66arvIUAO");
	ASSERT_EQ(actual, true);
}