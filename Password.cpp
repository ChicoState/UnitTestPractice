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
  int repetition = 1;
  int index = 0;

  if(phrase==""||phrase=="\n")
  {
    repetition=0;
  }

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  bool result=false;
  bool upper=false;
  bool lower=false;
  for(int i=0; i<phrase.size(); i++)
  {
    char current=phrase[i];
    int cur=int(current);
   /* if(cur>64)
    {
      if(cur<91)
      {
        upper=true;
      }
    }
    if(cur>96)
    {
      if(cur<123)
      {
        lower=true;
      }
    }
    i++;
  }*/
    if(std::isupper(current))
    {
      upper=true;
    }
    if(std::islower(current))
    {
      lower=true;
    }
}
  if(upper && lower)
    result=true;
  return result;
}
