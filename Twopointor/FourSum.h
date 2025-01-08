#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4)
            return result;
        for (int first = 0; first <= nums.size() - 4; first++)
        {
            if (nums[first] > target)
            {
                return result;
            }
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            for (int second = first + 1; second <= nums.size() - 3; second++)
            {
                // if (nums[first] + nums[second] > target)
                // {
                //     return result;
                // }
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                int left = second + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[first] + nums[second] + nums[left] + nums[right] == target)
                    {
                        result.push_back({nums[first], nums[second], nums[left], nums[right]});
                        while (nums[left + 1] == nums[left] && left < right)
                            left++;
                        while (nums[right - 1] == nums[right] && left < right)
                            right--;
                        left++;
                        right--;
                    }
                    else if (nums[first] + nums[second] + nums[left] + nums[right] > target)
                        right--;
                    else if (nums[first] + nums[second] + nums[left] + nums[right] < target)
                        left++;
                }
            }
        }
        return result;
    }
};