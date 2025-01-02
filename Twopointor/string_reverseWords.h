#include <iostream>
using namespace std;
class Solution
{
public:
    void reverse(string &s, int indexLeft, int indexRight)
    {
        char temp;
        int left = indexLeft, right = indexRight;
        while (left < right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
    void removeExtraSpace(string &s)
    {
        int slow = 0, fast = 0;
        while (fast < s.size() && s[fast] == ' ')
        {
            fast++;
        }
        // 去除中间的空格
        for (; fast < s.size(); fast++)
        {
            if (s[fast] == ' ' && s[fast - 1] == s[fast])
            {
                continue;
            }
            else
                s[slow++] = s[fast];
        }
        if (s[slow - 1] == ' ')
        {
            s.resize(slow - 1);
        }
        else
        {
            s.resize(slow);
        }
    }
    string reverseWords(string &s)
    { // 去除多余的空格
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0, i = 0;

        for (; start < s.size(); start += i + 1)
        {
            i = 0;
            while (s[start + i] != ' ' && start + i < s.size())
            {
                i++;
            }
            reverse(s, start, start + i - 1);
        }
        return s;
    }
};