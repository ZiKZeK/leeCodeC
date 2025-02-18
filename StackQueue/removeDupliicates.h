#ifndef REMOVEDUPLICATES_H
#define REMOVEDULPICATES_H
#include <string>
#include <stack>
using namespace std;
class Solution
{
    stack<char> st;

public:
    string removeDuplicates(string s)
    {
        for (auto ch : s)
        {
            if (st.empty() || ch != st.top())
            {
                st.push(ch);
            }
            else
            {
                st.pop();
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
#endif

// 直接使用字符串来作为栈，不用使用额外的空间
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string result;
        for (char s : S)
        {
            if (result.empty() || result.back() != s)
            {
                result.push_back(s);
            }
            else
            {
                result.pop_back();
            }
        }
        return result;
    }
};