#include "Practice.h"
#include <string>

using std::string;

// Receive three integers and rearrange their values so that they are in
// descending order from greatest (first) to least (third)
void Practice::sortDescending(int & first, int & second, int & third)
{
  int temp;
  if( second > first ){
    temp = first;
    first = second;
    second = temp;
  }
  if( third > first ){
    temp = first;
    first = third;
    third = temp;
  }
  if( third > second ){
    temp = third;
    third = second;
    second = temp;
  }
}

// Receive a string and return whether or not it is strictly a palindrome,
// where it is spelled the same backwards and forwards when considering every
// character in the string, but disregarding case ('x' is the same as 'X')
bool Practice::isPalindrome(string input)
{
  if( input.length() == 0 ){
    return true;
  }
  else{
    return ( toupper(input[0]) == toupper(input[input.size()-1]) && isPalindrome(input.substr(1, input.length()-2)) );
  }
}

// This function receives a string and counts how many times the same character
// is repeated at the beginning of the string, before any other characters. The
// function is case sensative so 'Z' is different than 'z'.
int Practice::count_starting_repeats(string word)
{
    int repetition = 1;
    char letter;

    if( word.length() == 0 )
      return 0;

    for(unsigned int i=0; i < word.length() - 1; i++){
      if( word[i] == word[i+1] ){
        repetition++;
      }
    }    

    return repetition;
}

// Receives an array that represents the hours someone sleeps each night of the week
// (as an array of seven integers) and returns a pointer to locate the first instance
// of an "all nighter" in the array (a day with 0 hours sleep) and returns the pointer. 
// However, if there are no such days found, the function should return nullptr.

/* Implementation A

int* Practice::allnighter(int sleep[7])
{
 return nullptr;
}
*/

/* Implementation B

int* Practice::allnighter(int sleep[7])
{
 return & sleep[0];
}
*/

/* Implementation C

int* Practice::allnighter(int sleep[7])
{
 int i=0;
 int *place = &sleep[i];
 while(place && place != nullptr)
 {
   place = &sleep[++i];
 }
 return place;
}
*/


/* Implementation D 

int* Practice::allnighter(int sleep[7])
{
 int i=0;
 int *place = &sleep[i];
 while(place && place != nullptr && i < 7)
 {
   place = &sleep[++i];
 }
 return place;
}
*/

/* Implementation E

int* Practice::allnighter(int sleep[7])
{
 int *place = nullptr;
 for(int i=0; i < 7; i++)
 {
    if( sleep[i] == 0 ){
      place = &sleep[i];
      return place;
    }
 }
 return place;
}
*/

/* Implementation F

int* Practice::allnighter(int sleep[7])
{
 int *place = nullptr;
 for(int i=0; i < 7; i++)
 {
   if( sleep[i] == 0 )
     place = &sleep[i];
 }
 return place;
}
*/
