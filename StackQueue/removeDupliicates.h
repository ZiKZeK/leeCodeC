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