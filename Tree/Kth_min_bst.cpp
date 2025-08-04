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


// Sol 2 : optimal 


class Solution {
private:
    void Inorder(TreeNode * root,int k ,int &count,int &ans){
        if(!root || count>=k) return ;
        Inorder(root->left,k,count,ans);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        Inorder(root->right,k,count,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int ans=-1,count=0;
        Inorder(root,k,count,ans);
        return ans;
    }
};

// TC -> O(K)
// SC -> O(H)
