#include <vector>
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         vector<vector<int>> Sum;
//         int len = nums.size();
//         for (int left = 0; left <= len - 3; left++)
//         {
//             for (int mid = left + 1; mid <= len - 2; mid++)
//                 for (int right = mid + 1; right <= len - 1; right++)
//                 {
//                     if (nums[left] + nums[mid] + nums[right] == 0)
//                     {
//                         Sum.push_back({nums[left], nums[mid], nums[right]});
//                     }
//                 }
//         }
//         return Sum; // 没有进行去重算法；
//     }
// };

// class Solution //使用哈希表的算法不是很合适
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end()); // 首先进行排序
//         //
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] > 0)
//                 break;
//             if (i > 0 && nums[i] == nums[i - 1]) // 保证这次循环不会遍历到之前的结果
//                 continue;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (j >= i + 2 && nums[j] == nums[j - 1])
//                 {
//                     continue;
//                 }
//                 int c = 0 - (nums[i] + nums[j]);
//                 if (nums.find(c) != nums.end())
//                 {
//                     result.push_back({nums[i], nums[j], c});
//                     nums.erase(c);
//                 }
//                 else
//                 {
//                     nums.insert(nums[j]);
//                 }
//             }
//         }
//         return result;
//     }
// };
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 首先进行排序
        if (nums.size() < 3)
            return result;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return result;
    }
};