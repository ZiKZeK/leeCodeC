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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return NULL;
        int breakValue = postorder[postorder.size() - 1];
        TreeNode *node = new TreeNode(breakValue);
        if (inorder.size() == 1)
        {
            return node;
        }

        int cutIdx;
        for (cutIdx = 0; cutIdx < inorder.size(); cutIdx++)
        {
            if (inorder[cutIdx] == breakValue)
                break;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + cutIdx);
        vector<int> rightInorder(inorder.begin() + cutIdx + 1, inorder.end());
        vector<int> leftpostorder(postorder.begin(), postorder.begin() + cutIdx);
        vector<int> rightpostorder(postorder.begin() + cutIdx, postorder.end() - 1);
        node->left = buildTree(leftInorder, leftpostorder);
        node->right = buildTree(rightInorder, rightpostorder);
        return node;
    }
};