#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Password
{
private:
  vector <string> pass_history;
public:
  /*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
  */
  int count_leading_characters(string);

  /*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
  */
  bool has_mixed_case(string);

  /*
  constructor sets the default password to "ChicoCA-95929"
  */
  Password();

  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void set(string);

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool authenticate(string);
};
#endif
