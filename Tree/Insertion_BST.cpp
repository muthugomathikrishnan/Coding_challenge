
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode * temp=root;
        TreeNode * parent=NULL;
        while(temp){
            parent=temp;
            temp=val<temp->val ? temp->left :temp->right;
        }
        TreeNode *n1=new TreeNode(val);
        if(val > parent->val) parent->right=n1;
        else parent->left=n1;
        return root;        
    }
};

// TC -> O(log n)
// SC -> O(1)
