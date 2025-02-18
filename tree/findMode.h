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
private:
    vector<int> result;
    int maxCount = 1;
    int count = 1;
    TreeNode *pre = nullptr;
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        traversal(root->left);

        if (pre != nullptr)
        {
            if (root->val == pre->val)
                count++;
            else
                count = 1;
            if (count == maxCount)
                result.push_back(root->val);
            if (count > maxCount)
            {
                maxCount = count;
                result.clear();
                result.push_back(root->val);
            }
        }
        else
        {
            result.push_back(root->val);
        }
        pre = root;
        traversal(root->right);
        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        maxCount = 1;
        count = 1;
        pre = nullptr;
        result.clear();
        traversal(root);
        return result;
    }
};