#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // ����Ҷ�ӽڵ㣬���Ҽ���Ϊ0
        if (!cur->left && !cur->right) return false; // ����Ҷ�ӽڵ�ֱ�ӷ���

        if (cur->left) { // ��
            count -= cur->left->val; // �ݹ飬����ڵ�;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // ���ݣ�����������
        }
        if (cur->right) { // ��
            count -= cur->right->val; // �ݹ飬����ڵ�;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // ���ݣ�����������
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};