// 完成右旋字符串功能
#include <iostream>
#include <string>
using namespace std;
void reverse(string &s, int start, int end);
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s, 0, s.size() - 1);
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    cout << s << endl;
    return 0;
}
void reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}