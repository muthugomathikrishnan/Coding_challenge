// S1=iterative
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


// S2 : recursion 

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(!root) return new TreeNode(val);
     if(val<root->val) root->left=insertIntoBST(root->left,val);
     if(val>root->val) root->right=insertIntoBST(root->right,val);
     return root;           
    }
};

/*
Time Complexity (TC): O(H)
Space Complexity (SC): O(H)
*/
