// Definition for a binary tree node.
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
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false; // 已经到底部了
        else if (left != nullptr && right == nullptr)
            return true;
        else if (left->val != right->val)
            return false; // 不相等一定是false，但是相等不一定是对的

        bool outside = compare(left->left, right->right); // 相等的情况下继续向下递归
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root = nullptr)
            return true;
        return compare(root->left, root->right);
    }
};