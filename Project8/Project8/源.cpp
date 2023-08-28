#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void trval(TreeNode* cur, vector<int>& path, vector<string>& result)
    {
        path.push_back(cur->val); //中  中为什么写在这里，因为是从该节点出发的
        // 这才到了叶子节点
        if (cur->left == nullptr && cur->right == nullptr)
        {
            string spath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            result.push_back(spath);
            return;
        }

        //有一个递归，就要有一个回溯

        if (cur->left)  //左
        {
            trval(cur->left, path, result);
            path.pop_back();   //回溯
        }
        if (cur->right)  //右
        {
            trval(cur->right, path, result);
            path.pop_back();    //回溯 
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr)return result;
        vector<int> path;
        trval(root, path, result);
        return result;
    }
};