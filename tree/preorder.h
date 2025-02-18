#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == nullptr)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            result.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return result;
    }
    // 处理数据的时候就是从出栈
    vector<int> inorderedTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == nullptr)
            return result;
        TreeNode *cur = root;
        st.push(root);
        while (!st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
                st.push(cur);
            }
        }
    }
    vector<int> inorderTraversal2(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {                    // 指针来访问节点，访问到最底层
                st.push(cur);    // 将访问的节点放进栈
                cur = cur->left; // 左
            }
            else
            {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val); // 中
                cur = cur->right;           // 右
            }
        }
        return result;
    }
    // 后序的迭代只用反转前序的代码
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left)
                st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right)
                st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }

    // 统一标记法
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root != nullptr)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                if (node->right)
                    st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left)
                    st.push(node->left);
            }
            else
            {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
    }
    // 可以直接用队列来计数
    //     vector<vector<int>> levelorder(TreeNode * root){
    //         vector<vector<int>> result;
    //         vector<int> hold;
    //         queue<TreeNode*> TN;
    //         TN.push(root);
    //         int NumTN = 1;
    //         while(!TN.empty()){
    //             int count = NumTN;
    //             NumTN = 0;
    //             hold = {};
    //             while(count--){
    //                 TreeNode * temp = TN.front();
    //                 TN.pop();
    //                 hold.push_back(temp->val);
    //                 if(temp->left) {TN.push(temp->left);NumTN++;}
    //                 if(temp->right) {TN.push(temp->right);NumTN++;}
    //             }
    //             result.push_back(hold);
    //         }
    // return result;
    //     }
    // };

    // 广度优先算法 （使用队列结构）
    vector<vector<int>> levelorder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> que;
        if (!root)
            return result;
        que.push(root);
        while (!que.empty())
        {
            int que_size = que.size();
            vector<int> hold;
            while (que_size--)
            {
                TreeNode *temp = que.front();
                que.pop();
                hold.push_back(temp->val);
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
            result.push_back(hold);
        }
        return result;
    }
};

// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;
// struct TreeNode{
//     int val;
//     TreeNode * left;
//     TreeNode * right;
//     TreeNode(int x):val(x), left(nullptr), right(nullptr){}
// };
// class Solution{
//     public:
//     vector<int> preorderTraversal(TreeNode * root){
//         stack<TreeNode * > st;
//         vector<int> result;
//         if(root == nullptr) return result;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode * node = st.top();
//             result.push_back(node->val);
//             if(node->right) st.push(node->right);
//             if(node->left) st.push(node->left);
//         }
//         return result;
//     }
//     //处理数据的时候就是从出栈
//     vector<int> inorderedTraversal(TreeNode * root){
//         stack<TreeNode *> st;
//         vector<int> result;
//         if(root == nullptr) return result;
//         TreeNode * cur = root;
//         st.push(root);
//         while(!st.empty()){
//             if(cur!=nullptr){
//                 st.push(cur);
//                 cur = cur->left;
//             }else{
//                 cur = st.top();
//                 st.pop();
//                 result.push_back(cur->val);
//                 cur = cur->right;
//                 st.push(cur);
//             }
//         }
//     }
//      vector<int> inorderTraversal2(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode* cur = root;
//         while (cur != NULL || !st.empty()) {
//             if (cur != NULL) { // 指针来访问节点，访问到最底层
//                 st.push(cur); // 将访问的节点放进栈
//                 cur = cur->left;                // 左
//             } else {
//                 cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
//                 st.pop();
//                 result.push_back(cur->val);     // 中
//                 cur = cur->right;               // 右
//             }
//         }
//         return result;
//     }
//     //后序的迭代只用反转前序的代码
//     vector<int> postorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> result;
//         if (root == NULL) return result;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             result.push_back(node->val);
//             if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
//             if (node->right) st.push(node->right); // 空节点不入栈
//         }
//         reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
//         return result;
//     }
//     //统一标记法 中序法
//     vector<int> inorderTraversal(TreeNode * root){
//         stack<TreeNode*> st;
//         vector<int> result;
//         if(root!=nullptr) st.push(root);
//         while(!st.empty()) {
//              TreeNode * node = st.top();
//             if(node!= nullptr){
//                 st.pop();
//                 if(node->right) st.push(node->right);
//                 st.push(node);
//                 st.push(nullptr);
//                 if(node->left) st.push(node->left);
//             }
//             else{
//                 st.pop();
//                 result.push_back(st.top()->val);
//                 st.pop();
//             }
//         }
//     }
//     // 统一标记法 前序法
//     vector<int> preorderTraversal(TreeNode * root){
//         stack<TreeNode*> st;
//         vector<int> result;
//         if(root!=nullptr) st.push(root);
//         while(!st.empty()) {
//              TreeNode * node = st.top();
//             if(node!= nullptr){
//                 st.pop();
//                 if(node->right) st.push(node->right);
//                 if(node->left) st.push(node->left);
//                 st.push(node);
//                 st.push(nullptr);
//             }
//             else{
//                 st.pop();
//                 result.push_back(st.top()->val);
//                 st.pop();
//             }
//         }
//     }
//     //统一标记法后序法
//     vector<int> postorderTraversal(TreeNode * root){
//         stack<TreeNode*> st;
//         vector<int> result;
//         if(root!=nullptr) st.push(root);
//         while(!st.empty()) {
//              TreeNode * node = st.top();
//             if(node!= nullptr){
//                 st.pop();
//                 st.push(node);
//                  st.push(nullptr);
//                 if(node->right) st.push(node->right);
//                  if(node->left) st.push(node->left);
//             }
//             else{
//                 st.pop();
//                 result.push_back(st.top()->val);
//                 st.pop();
//             }
//         }
//     }
// };