// Sol 1: Brute Force 
class Solution {
private:
    bool getpath(TreeNode* root, int v, vector<TreeNode*>& arr) {
        if (!root) return false;
        arr.push_back(root);
        if (root->val == v) return true;
        if (getpath(root->left, v, arr) || getpath(root->right, v, arr)) return true;
        arr.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        getpath(root, p->val, path_p);
        getpath(root, q->val, path_q);
        int i = 0;
        while (i < path_p.size() && i < path_q.size() && path_p[i] == path_q[i]) i++;
        return path_p[i - 1];
    }
};
// TC -> O(N) + O(N)
// SC -> O(N) + O(N)


// Optimal 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};
// TC -> O(N)
// SC -> O(N)
