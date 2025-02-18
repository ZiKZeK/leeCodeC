#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        if (nums[0] >= nums.size() - 1)
            return 1;
        int step = 1;
        int i = 0;
        int j = i + nums[i];
        int maxlen = j + nums[j];
        while (j < nums.size() - 1)
        {
            int temp = j;
            while (i < j)
            {
                if (i + nums[i] > maxlen)
                {
                    maxlen = i + nums[i];
                    if (maxlen >= nums.size() - 1)
                        return step + 1;
                    temp = i;
                }
                i++;
            }
            i = temp;
            j = i + nums[i];
            maxlen = j + nums[j];
            step++;
        }
        return step;
    }
};