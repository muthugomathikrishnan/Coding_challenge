// Link :https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode * temp=root->right;
        root->right=root->left;
        root->left=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
