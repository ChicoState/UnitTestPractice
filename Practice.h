#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>

using std::string;

class Practice
{
public:
  void sortDescending(int & first, int & second, int & third);
  bool isPalindrome(string input);
  int count_starting_repeats(string word);
  int* allnighter(int sleep[7]);
};
#endif
