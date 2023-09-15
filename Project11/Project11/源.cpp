class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // ������������ת��Ϊ��������
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear(); // ���������leetcode��Ҳ���Թ�������ü���
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // ע��ҪС�ڵ��ڣ��������ﲻ������ͬԪ��
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
}; 
