#include <string>
#include <stack>
using namespace std;
#ifndef ISVALID_H
#define ISVALID_H
class Solution
{
    stack<char> bracket;

public:
    bool isValid(string s)
    {
        for (auto ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                bracket.push(ch); // 这里可以如果push
            }
            else
            {
                if (bracket.empty())
                    return false;
                // if (ch == bracket.top())  //不是相等关系，而是配对关系
                char top = bracket.top();
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']'))
                {
                    bracket.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return bracket.empty();
    }
};
#endif