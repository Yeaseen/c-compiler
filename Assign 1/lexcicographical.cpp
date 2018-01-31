// lexicographical_compare example
#include <iostream>     // std::cout, std::boolalpha
#include <algorithm>    // std::lexicographical_compare
#include <cctype>       // std::tolower

using namespace std;
// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () {
  char foo[]="ABC";
  char bar[]="ABCD";

  //cout << boolalpha;

  cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  cout << "Using default comparison (operator<): ";
  cout << lexicographical_compare(foo,foo+3,bar,bar+2);
  cout << '\n';

  //std::cout << "Using mycomp as comparison object: ";
  //std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  //std::cout << '\n';

  return 0;
}
