// Link : https://leetcode.com/problems/recover-binary-search-tree/
// Sol 1: Inorder Traversal

class Solution {
private:
    TreeNode * first=NULL;
    TreeNode * second=NULL;
    TreeNode * prev=NULL;
    
    void Inorder(TreeNode * root){
        if(!root) return ;
        Inorder(root->left);
        if(prev && prev->val>root->val){
            if(!first) first=prev;
            second=root;
        }
        prev=root;
        Inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        Inorder(root);
        swap(first->val,second->val);
        
    }
};

// TC -> O(N)
// SC -> O(N)
