// Link :

// Sol 1: brute force approach 


class Solution {
private:
    void Inorder(TreeNode * root,vector<int>&val){
        if(!root) return;
        Inorder(root->left,val);
        val.push_back(root->val);
        Inorder(root->right,val);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return 0;
        vector<int>val,val2;
        Inorder(root,val);
        val2=val;
        sort(val2.begin(),val2.end());

        for(int i=0;i<val.size()-1;i++){
            if(val2[i]==val2[i+1]) return 0;
            if(val[i]!=val2[i]) return 0;
        }
        return 1;
    }
};

// TC -> O(N Log N)
// SC -> O(1)
