#include <iostream>
#include <string.h>
using namespace std;
string toUpper(string str, int len)
{
  int c=0;
  string str1;
  for(c=0; c<len; c++)
  {
    if(str[c]>='A' && str[c]<='Z')
      str1[c] = str[c];
      
    else
      str1[c] = (str[c] - 32);  
  }
  cout<< "\nUpper Case: ";
  for(c=0; c<len; c++)
  {
    cout<< str1[c];
  }
  return str1;
}
string toLower(string str, int len)
{
  int c=0;
  string str1;
  for(c=0; c<len; c++)
  {
    if(str[c]>='A' && str[c]<='Z')
      str1[c] = str[c] + 32;
      
    else
      str1[c] = str[c]; 
  }
  cout<< "\nLower Case: ";
  
for(c=0; c<len; c++)
  {
    cout<< str1[c];
  }
  return str1;
}
int main()
{
  int len = 0, c;
  string str;
  cout<< "Enter a string: ";
  cin>> str;
  len = str.size();
  
  toUpper(str, len);
  toLower(str, len);
  
  return 0;
}
