#include<iostream>
#include<vector>
using namespace std;
 void reverseString(vector<char> s);
 int main()
 {}
  void reverseString(vector<char> s)
  {
    char temp;
    for(int i = 0, j = s.size() - 1; i >= j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }};