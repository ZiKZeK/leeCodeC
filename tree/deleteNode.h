#include <queue>
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
class Solution
{
private:
    TreeNode *findMin(TreeNode *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode *traversal(TreeNode *root, int key)
    {
        if (root == NULL)
            return nullptr;
        if (root->val > key)
            root->left = traversal(root->left, key);
        else if (root->val < key)
            root->right = traversal(root->right, key);
        else
        {
            if (root->left == nullptr && root->right == nullptr) // 左边是空的
            {
                delete root;
                return nullptr;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                return root->left;
            }
            else if (root->left == nullptr && root->right != nullptr) //
            {
                return root->right;
            }
            else
            {
                TreeNode *node = findMin(root->right);
                node->left = root->left;
                return root->right;
            }
        }
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return traversal(root, key);
    }
};
// class Solution
// {
// private:
//     TreeNode *findMin(TreeNode *root)
//     {
//         TreeNode *node = root;
//         while (node->left)
//         {
//             node = node->left;
//         }
//         return node;
//     }
//     void traversal(TreeNode *root, int key)
//     {
//         if (root == NULL)
//             return;
//         if (root->val > key)
//             traversal(root->left, key);
//         else if (root->val < key)
//             traversal(root->right, key);
//         else
//         {
//             if (root->left == nullptr) // 左边是空的
//             {
//                 root->val = root->right->val;
//                 root->left = root->right->left;
//                 root->right = root->right->right;
//                 return;
//             }
//             else if (root->right == nullptr)
//             {
//                 root->val = root->left->val;
//                 root->right = root->left->right;
//                 root->left = root->left->left;
//             }
//             else // 左右都不是空
//             {
//                 TreeNode *temp = root->left;
//                 root->val = root->right->val;
//                 root->left = root->right->left;
//                 root->right = root->right->right;
//                 TreeNode *minNode = findMin(root->left);
//                 return;
//             }
//         }
//         return;
//     }

// public:
//     TreeNode *deleteNode(TreeNode *root, int key)
//     {
//         traversal(root, key);
//         return root;
//     }
// };