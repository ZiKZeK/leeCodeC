// #include <iostream>
// using namespace std;
// #include <vector>
// #include <string>
// #include "charArr.h"
// using namespace std;

// int main()
// {
//     string s;
//     while (cin >> s)
//     {
//         int count = 0;
//         int oldIndex = s.length();
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] <= '9' && s[i] >= '0')
//                 count++;
//         }
//         s.resize(oldIndex + count * 5);
//         int newIndex = s.size() - 1;
//         oldIndex--;
//         while (newIndex >= 0)
//         {
//             if (s[oldIndex] <= '9' && s[oldIndex] >= '0')
//             {
//                 s[newIndex--] = 'r';
//                 s[newIndex--] = 'e';
//                 s[newIndex--] = 'b';
//                 s[newIndex--] = 'm';
//                 s[newIndex--] = 'u';
//                 s[newIndex--] = 'n';
//             }
//             else
//             {
//                 s[newIndex--] = s[oldIndex];
//             }
//             oldIndex--;
//         };
//         cout << s << endl;
//     }
// }