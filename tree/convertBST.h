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
// 采用后序遍历进行累加
class Solution
{
private:
    TreeNode *pre;
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        else
        {
            traversal(root->right);
            if (pre->val == nullptr) //
            {
                pre->val = root->val;
            }
            else
            {
                root->val = pre->val;
                pre = root;
            }
            traversal(root->left);
        }
        return;
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        TreeNode *pre = new TreeNode(0);
        traversal(root);
        return root;
    }
};