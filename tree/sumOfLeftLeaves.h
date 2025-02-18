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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

class Solution2
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        stack<TreeNode *> nodeSt;
        int result;
        if (root == NULL)
            return 0;
        nodeSt.push(root);
        while (!nodeSt.empty())
        {
            TreeNode *node = nodeSt.top();
            if (node->left != NULL && node->left->right == NULL && node->left->left == NULL)
            {
                result += node->left->val;
            }
            nodeSt.pop();
            if (node->left)
                nodeSt.push(node->left);
            if (node->right)
                nodeSt.push(node->right);
        }
        return result;
    }
};
