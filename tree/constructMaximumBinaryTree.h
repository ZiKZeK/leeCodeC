#include <vector>
#include <string>
#include <stack>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            TreeNode *node = new TreeNode(nums[0]);
            return node;
        }
        int maximum = INT_MIN;
        int maxIdx = 0;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            if (nums[idx] > maximum)
            {
                maxIdx = idx;
                maximum = nums[maxIdx];
            }
        }
        TreeNode *node = new TreeNode(nums[maxIdx]);
        if (maxIdx > 0)
        {
            vector<int> leftnums(nums.begin(), nums.begin() + maxIdx);
            node->left = constructMaximumBinaryTree(leftnums);
        }
        if (maxIdx < nums.size() - 1)
        {
            vector<int> rightnums(nums.begin() + maxIdx + 1, nums.end());
            node->right = constructMaximumBinaryTree(rightnums);
        }
        return node;
    }
};

class Solution2
{
private:
    // 在左闭右开区间[left, right)，构造二叉树
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return nullptr;

        // 分割点下标：maxValueIndex
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i)
        {
            if (nums[i] > nums[maxValueIndex])
                maxValueIndex = i;
        }

        TreeNode *root = new TreeNode(nums[maxValueIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);

        // 左闭右开：[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size());
    }
};