#include <vector>
#include <string>
#include <queue>
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
    TreeNode *traversal(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *node = new TreeNode();
        if (!root1 && !root2)
            return NULL;
        else
        {
            if (!root1)
            {
                node->val = root2->val;
                node->left = traversal(NULL, root2->left);
                node->right = traversal(NULL, root2->right);
            }
            else if (!root2)
            {
                node->val = root1->val;
                node->left = traversal(root1->left, NULL);
                node->right = traversal(root1->right, NULL);
            }
            else
            {
                node->val = root1->val + root2->val;
                node->left = traversal(root1->left, root2->left);
                node->right = traversal(root1->right, root2->right);
            }
        }
        return node;
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return traversal(root1, root2);
    }
};

// 采用队列， 将二叉树2加入到二叉树1上面， 其中如果二叉树1是空的话， 二就可以直接替换1
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        queue<TreeNode *> que;
        que.push(t1);
        que.push(t2);
        while (!que.empty())
        {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            // 此时两个节点一定不为空，val相加
            node1->val += node2->val;

            // 如果两棵树左节点都不为空，加入队列
            if (node1->left != NULL && node2->left != NULL)
            {
                que.push(node1->left);
                que.push(node2->left);
            }
            // 如果两棵树右节点都不为空，加入队列
            if (node1->right != NULL && node2->right != NULL)
            {
                que.push(node1->right);
                que.push(node2->right);
            }

            // 当t1的左节点 为空 t2左节点不为空，就赋值过去
            if (node1->left == NULL && node2->left != NULL)
            {
                node1->left = node2->left;
            }
            // 当t1的右节点 为空 t2右节点不为空，就赋值过去
            if (node1->right == NULL && node2->right != NULL)
            {
                node1->right = node2->right;
            }
        }
        return t1;
    }
};