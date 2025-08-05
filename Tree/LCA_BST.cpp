// Soltuion 1 : brute force approach 



class Solution {
private:
    bool getpath(TreeNode *root, int val, vector<TreeNode*>&ans){
        if(!root) return 0;
        ans.push_back(root);
        if(root->val==val) return 1;
        if(root->val<val) { getpath(root->right,val,ans); return true; }
        if(root->val>val) { getpath(root->left,val,ans); return true; }
        ans.pop_back();
        return 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*>path_p,path_q;
        
        getpath(root,p->val,path_p);
        getpath(root,q->val,path_q);
        int i=0;
        while(i<path_p.size() && i<path_q.size() && path_p[i]==path_q[i]) i++;
        return path_p[i-1];        
    }
};


// TC ->(H)
// SC ->(H)

