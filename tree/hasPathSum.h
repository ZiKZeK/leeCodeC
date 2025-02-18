#include <stack>
#include <vector>
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        stack<int> pathSumSt;
        stack<TreeNode *> st;
        if (root == NULL)
            return false;
        st.push(root);
        pathSumSt.push(root->val);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            int pathSum = pathSumSt.top();
            pathSumSt.pop();
            if (node->left == NULL && node->right == NULL)
            {
                if (pathSum == targetSum)
                    return true;
            }
            if (node->left)
            {
                st.push(node->left);
                pathSumSt.push(pathSum + node->left->val);
            }
            if (node->right)
            {
                st.push(node->right);
                pathSumSt.push(pathSum + node->right->val);
            }
        }
        return false;
    }
};

// 方法二 ，使用递归
class Solution
{
public:
    bool traversal(TreeNode *root, int count)
    {
        if (!root->left && !root->right && count == 0)
            return true;
        if (!root->left && !root->right)
            return false;
        if (root->left)
        {
            count -= root->left->val;
            if (traversal(root->left, count))
                return true;
            count += root->left->val;
        }
        if (root->right)
        {
            count -= root->right->val;
            if (traversal(root->right, count))
                return true;
            count += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        return traversal(root, targetSum - root->val);
    }
};