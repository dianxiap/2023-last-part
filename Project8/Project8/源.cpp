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
        path.push_back(cur->val); //��  ��Ϊʲôд�������Ϊ�ǴӸýڵ������
        // ��ŵ���Ҷ�ӽڵ�
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

        //��һ���ݹ飬��Ҫ��һ������

        if (cur->left)  //��
        {
            trval(cur->left, path, result);
            path.pop_back();   //����
        }
        if (cur->right)  //��
        {
            trval(cur->right, path, result);
            path.pop_back();    //���� 
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