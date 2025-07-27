// Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/?source=submission-ac
//Solution 1: DFS and hash set


class Solution {
    bool DFS(TreeNode* root,unordered_set<int>&seen,int k){
        if(!root) return 0;
        if(seen.count(k-root->val)) return true;
        seen.insert(root->val);
        return DFS(root->left,seen,k)|| DFS(root->right,seen,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        unordered_set<int>seen;
        return DFS(root,seen,k);
    }
};

// TC -> O(N)
// SC -> O(N)


// Sol 2: Inorder

class Solution {
    void Inorder(TreeNode* root,vector<int>&arr){
        if(!root) return ;
        Inorder(root->left,arr);
        arr.push_back(root->val);
        Inorder(root->right,arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        Inorder(root,arr);
        int l=0,r=arr.size()-1;
        while(l<r){
            if(k==arr[l]+arr[r]) return true;
            if(k<arr[l]+arr[r]) r--;
            else l++;
        }
        return false;
    }
};
// TC -> O(N)
// SC -> O(N)
