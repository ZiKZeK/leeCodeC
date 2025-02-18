#include <vector>
#include <string>
#include <stack>
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
    vector<int> Arr;
    void TreetoArr(TreeNode *root)
    {
        if (!root)
            return;
        TreetoArr(root->left);
        Arr.push_back(root->val);
        TreetoArr(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        TreetoArr(root);
        int idx = 1;
        int result = Arr[1] - Arr[0];
        while (idx < Arr.size() - 1)
        {
            if (result >= Arr[idx + 1] - Arr[idx])
            {
                result = Arr[idx + 1] - Arr[idx];
            }
            idx += 1;
        }
        return result;
    }
};

// 记录前面一个指针 然后直接采用前一个和后一个的差值，相当于在进行中旭遍历的时候直接比较

class Solution
{
private:
    int result = INT_MAX;
    TreeNode *pre = NULL;
    void traversal(TreeNode *cur)
    {
        if (cur == NULL)
            return;
        traversal(cur->left); // 左
        if (pre != NULL)
        { // 中
            result = min(result, cur->val - pre->val);
        }
        pre = cur;             // 记录前一个
        traversal(cur->right); // 右
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};