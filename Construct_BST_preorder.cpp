// Link :

// Sol :

class Solution {
private:
    TreeNode * s(vector<int>& preorder,int mini, int maxi, int & i){
        if(i>=preorder.size()) return NULL;
        if(preorder[i]>=maxi || preorder[i]<=mini) return NULL;
        TreeNode * root= new TreeNode(preorder[i++]);
        root->left=s(preorder,mini,root->val,i);
        root->right=s(preorder,root->val,maxi,i);
        return root;
    } 
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return s(preorder,INT_MIN,INT_MAX,i);
    }
};

// TC: O(n)
// SC: O(h)
