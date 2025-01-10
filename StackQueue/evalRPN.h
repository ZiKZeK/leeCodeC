#include <string>
#include <vector>
#include <stack>
using namespace std;
#ifndef EVALRPN_H
#define EVALRPN_H
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (auto ch : tokens)
        {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (ch == "+")
                    st.push(num2 + num1);
                if (ch == "-")
                    st.push(num2 - num1);
                if (ch == "*")
                    st.push(num2 * num1);
                if (ch == "/")
                    st.push(num2 / num1);
            }
            else
            {
                st.push(stoll(ch));
            }
        }
        long long result = st.top();
        return result;
    }
};
#endif