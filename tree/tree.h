#ifndef TREE_H
#define TREE_H
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    // 前序遍历
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 中序遍历
    void traversal2(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        traversal2(cur->left, vec);
        vec.push_back(cur->val);
        traversal2(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal2(root, result);
        return result;
    }
    // 后序遍历
    void traversal3(TreeNode *cur, vector<int> vec)
    {
        if (cur == nullptr)
            return;
        traversal3(cur->left, vec);
        traversal3(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal3(root, result);
        return result;
    }
};

#endif
