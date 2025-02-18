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
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
        }
        else
        {
            if (cur->left)
            {
                traversal(cur->left, path, result);
                path.pop_back();
                // 这里的出站类似于递归的回溯
            }
            if (cur->right)
            {
                traversal(cur->right, path, result);
                path.pop_back();
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        if (root == NULL)
            return result;
        traversal(root, path, result);
        return result;
    }
};
// 递归思想 左边右边相加

// 迭代思想
class Solution2
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        stack<string> pathSt;
        stack<TreeNode *> treeSt;
        if (root == NULL)
            return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty())
        {
            TreeNode *node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node->left == NULL && node->right == NULL)
            {
                result.push_back(path);
            }
            if (node->right)
            {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left)
            {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};