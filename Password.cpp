#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if(phrase.empty()){
    return 0;
  }
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string str){
  bool upper = false;
  bool lower = false;
  for(char c : str){
    if(c >= 'a' && c <= 'z'){
      lower = true;
    }else if(c >= 'A' && c <= 'Z'){
      upper = true;
    }
    if(upper && lower){
      return true;
    }
  }
  return false;
}
