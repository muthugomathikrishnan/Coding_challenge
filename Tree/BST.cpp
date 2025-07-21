
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
     while(root && root->val!=val){
        root=val<root->val? root->left : root->right;
     }
     return root;   
    }
};
// TC -> O(Log N)
// SC -> O(1)
