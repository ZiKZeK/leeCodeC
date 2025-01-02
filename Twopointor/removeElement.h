#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &arr, int val)
    {
        int slow = 0, fast = 0;
        int len = arr.size();
        while (fast < len)
        {
            if (arr[fast] != val)
            {
                arr[slow] = arr[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};