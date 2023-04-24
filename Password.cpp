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

  if(phrase.length() == 0)
  {
	return 0;
  }
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
bool Password::has_mixed_case(string phrase)
{
	int lower = 0;
	int upper = 0;
	int index = 0;
	
	while(index < phrase.length())
	{
		if(isupper(phrase[index]))
		{
			upper = 1;
		}
		else
		{
			lower = 1;
		}
		index ++;
	}

	return (upper && lower);

	
}*/
/*
bool Password::has_mixed_case(string phrase){ bool upper = false; bool lower = false; for(auto &c : phrase){ if(upper && lower){ return true; } if(isupper(c)){ upper = true; } else if(islower(c)){ lower = true; } } return false; }
*/
/*
bool Password::has_mixed_case(string password){ int length = password.length(); string upper=password, lower=password; for(int i=0; i < password.length(); i++){ upper[i] = toupper(password[i]); lower[i] = tolower(password[i]); } return password != upper && password != lower; }*/
/*
bool Password::has_mixed_case(string phrase){ bool upper = false, lower = false; for(char a : phrase){ isupper(a) ? upper = true : islower(a) ? lower = true : lower = false; } return upper || lower ? true : false; }*/

bool Password::has_mixed_case(string phrase) { 
	bool upper = false; 
	bool lower = false; 
	if (phrase.length() < 1 || phrase.length() == 0) { 
		return false; 
	} 
	for (int i = 0; i < phrase.length(); i++) { 
		if (isupper(phrase[i])) { 
			upper = true; 
		} 
		if (islower(phrase[i])) { 
			lower = true; 
		} 
		if (phrase[i] == ' ') { 
			return false; 
		} 
	} 
	if (lower && upper) { 
		return true; 
	} 
	return false; 
}
/*
bool Password::has_mixed_case(string phrase) { if(phrase[0] == phrase[1]) { return false; } else if(isupper(phrase[0]) != islower(phrase[1])) { return true; } else if(islower(phrase[0]) != isupper(phrase[1])) { return true; } else { return false; } }
*/
