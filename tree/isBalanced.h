#include <cmath>
#include <algorithm>
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
// 引入-1使得只要存在一个不合理的值，后续所有的深度都是不合理的，最后只用判断根节点的值是不是-1即可
class Solution
{
public:
    // 返回树的高度，如果发现不平衡，返回 -1
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = height(node->left);
        if (leftHeight == -1)
            return -1; // 左子树不平衡

        int rightHeight = height(node->right);
        if (rightHeight == -1)
            return -1; // 右子树不平衡

        if (abs(leftHeight - rightHeight) > 1)
            return -1; // 当前节点不平衡

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
};
