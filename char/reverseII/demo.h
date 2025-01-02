
// #include<string>
// class solution
// {
//     public:
//     void reverseStringII(string s, int k)
//     {
//         char temp;
//         int len = 0;
//         for(; s.size() - len + 1 >= 2 * k; len+=2 * k)
//         {
//             for(int i = len, j =len + k - 1; i < j; i++, j--)
//             { temp = s[j];
//               s[i] = s[j];
//               s[j] = temp;
//             } 
//         }
//         if (s.size - len + 1 < k)
//         {
//             for(int i = len, j = s.size() - 1; i < j; i++, j--)
//             {
//               temp = s[j];
//               s[i] = s[j];
//               s[j] = temp;
//             }
//         }
//         else {
//             for(int i = len, j =len + k - 1; i < j; i++, j--)
//             {
//               temp = s[j];
//               s[i] = s[j];
//               s[j] = temp;
//             }
//         }
//     }
// }
// //可以用更简单的代码写
