#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int Findnum(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                num++;
            }
        }
        return num;
    }
    void replace_elements(string &s)
    {
        int num = Findnum(s);
        int len = s.size();
        s.resize(len + num * 5);
        int oldIndex = len - 1;
        int newIndex = s.size() - 1;
        a1 for (; oldIndex >= 0; oldIndex--)
        {
            if (s[oldIndex] <= '9' && s[oldIndex] >= '0')
            {
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            }
            else
            {
                s[newIndex--] = s[oldIndex];
            }
        }
    }
};
int main()
{
    string s;
    cin >> s;                // 输入字符串
    Solution sol;            // 创建 Solution 对象
    sol.replace_elements(s); // 调用成员函数
    cout << s;               // 输出结果
    return 0;
}