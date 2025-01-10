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
                bracket.push(ch);
            }
            else
            {
                if (bracket.empty())
                    return false;
                if (ch == bracket.top())
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