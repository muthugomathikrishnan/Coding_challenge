// Reursion :
class Solution {
private:
    TreeNode* construct(vector<int>&preorder,int Pre_s,int Pre_e,vector<int>&inorder,int In_s,int In_e,unordered_map<int,int>&mp){
        if(Pre_s>Pre_e || In_s>In_e) return NULL;
        TreeNode * root=new TreeNode(preorder[Pre_s]);
        int root_ind=mp[root->val];
        int num_left=root_ind-In_s;

        root->left=construct(preorder,Pre_s+1,Pre_s+num_left,inorder,In_s,root_ind-1,mp);
        root->right=construct(preorder,Pre_s+num_left+1,Pre_e,inorder,root_ind+1,In_e,mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int Pre_e=preorder.size()-1,In_e=inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<=In_e;i++) mp[inorder[i]]=i;
        TreeNode * root=construct(preorder,0,Pre_e,inorder,0,In_e,mp);
        return root;        
    }
};

// TC -> O(N)
// SC -> O(N)
