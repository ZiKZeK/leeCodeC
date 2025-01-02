#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char temp;
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
};