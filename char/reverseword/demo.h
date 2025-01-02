#include <iostream>
#include<string>
class solution
{
    public:
    void reverseWord(string& s)
    {
        //去除单词之间的空格
        int slowIndex = 0, fastIndex = 0;
        //去除一开始的字符串，使用快指针进行跳过
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for(; fastIndex < s.size; fastIndex++)
        {
            if(fastIndex> 0 
                && s[fastIndex - 1] == s[fastIndex]
                && s[fastIndex] == ' ')  //判断是否有连续的空格
            {continue;} //快指针跳过空格
            else{
                s[slowIndex++] = s[fastIndex];
            }
            //末尾可能会出现一个空格
        }
        if (slowIndex> 0 && s[slowIndex - 1] == ' ')
        {s.resize(slowIndex - 1);}
        else{
            s.resize(slowIndex);
        }
    }
    void reverseString(string & s, int start, int end)
  {
    for(int i = start, j = end; i >= j; i++, j--)
  { swap(s[i], s[j]);
  }}
    string reverseWord(string s)
    {
        reverseString(s, 0,  s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(i == s.size() || s[i] == ' ')
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }
    return s;
    }
};