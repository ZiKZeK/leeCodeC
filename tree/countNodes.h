#include <queue>
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
    int countNodes(TreeNode *root)
    {
        int result = 0;
        queue<TreeNode *> que;
        if (!root)
            return result;
        que.push(root);
        result++;
        while (!que.empty())
        {
            int que_size = que.size();
            while (que_size--)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left)
                {
                    que.push(temp->left);
                    result++;
                }
                if (temp->right)
                {
                    que.push(temp->right);
                    result++;
                }
            }
        }
        return result;
    }
};