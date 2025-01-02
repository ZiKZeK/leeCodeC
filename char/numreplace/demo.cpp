#include <iostream>
#include <string>
using  namespace std;
int main()
{
    string s;
    while(cin >> s)
    {
        int count = 0;
        int len = s.size() - 1;
        for(int i = 0; i <= len; i++)
        {
            if(s[i] <= '9' && s[i] >='0')
               {count++;}
        }

        s.resize(s.size() + count * 5); // 重新改变字符串大小
        //从后往前开始改数据
        int newIndex = s.size() - 1;
        int slowp = len;
        while(newIndex>=0)
        {
            if(s[slowp] <= '9' && s[slowp] >= '0')
            {
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            }
            else{
                s[newIndex--] = s[slowp];
            }
            slowp--;
        }
        cout <<s << endl;
    }
}
    
