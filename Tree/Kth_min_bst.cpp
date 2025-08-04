// Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Sol 1 : Using Inorder

class Solution {
private:
    void Inorder(TreeNode * root, vector<int>&ans){
        if(!root) return ;
        Inorder(root->left,ans);
        ans.push_back(root->val);
        Inorder(root->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int>ans;
        Inorder(root,ans);
        if(k>ans.size()) return -1;
        return ans[k-1];
    }
};

// TC -> O(N)
// SC -> O(N)
