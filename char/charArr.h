#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            char temp;
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
        }
    }
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    string reverseStringII(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k <= s.size())
            {
                reverse(s, i, i + k - 1);
                continue;
            }
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
    // 去除多余的空格
    void removeExtraSpaces(string &s)
    { // 去除前面的空格
        int slowIndex = 0, fastIndex = 0;
        for (; fastIndex < s.size() && s[fastIndex] == ' '; fastIndex++)
        {
        }
        for (; fastIndex < s.size(); fastIndex++)
        {
            if (fastIndex > 1 && s[fastIndex] == s[fastIndex - 1] && s[fastIndex] == ' ')
            {
                continue;
            }
            else
                s[slowIndex++] = s[fastIndex]; // 第一个不是空格直接开始赋值了
        }
        // 去除后面的空格
        if (slowIndex > 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else
            s.resize(slowIndex);
    }

    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, s.size() - 1);
        return s;
    }

    // KMP 算法代码
    // 构造next数组（前缀表）
    void getNext(int *next, const string &s)
    {
        // 1 初始化
        int j = -1;
        next[0] = j; // 前缀表要统一减一的操作
        // 2 处理前后缀不相同的情况
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                // 在前一格的前缀表存在大于一的公共前缀时，前缀不相同，则前缀表要向前移动
                j = next[j];
            }
            if (s[i] == s[j + 1])
            { // 前缀相同，则前缀表要向后移动
                j++;
            }
            next[i] = j;
        }
        // 使用next数组来做匹配的过程

        for (int i = 0; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != t[j + 1])
            {
                j = next[j];
            }
            if (s[i] == t[j + 1])
            {
                j++;
            }
            if (j == t.size() - 1)
            {
                return (i - t.size() + 1);
            }
        }
    }
};
#endif