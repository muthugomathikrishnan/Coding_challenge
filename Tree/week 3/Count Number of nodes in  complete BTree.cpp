// Link : https://leetcode.com/problems/count-complete-tree-nodes
// Brute force solution:

class Solution {
private:
    void preorder(TreeNode * root,int &count){
        if(!root) return ;
        count++;
        preorder(root->left,count);
        preorder(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        preorder(root,count);
        return count;
    }
};

// TC -> O(N)
// SC -> O(N)
