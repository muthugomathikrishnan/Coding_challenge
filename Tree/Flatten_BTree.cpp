// Sol 1 : recursion 
class Solution {
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
// TC -> O(N)
// SC -> O(N)

// Sol 2 : Iterative 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            curr->left = NULL;
            if (!st.empty()) curr->right = st.top();
        }
    }
};
// TC -> O(N)
// SC -> O(N)


// Sol 3: using Morris
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
// TC -> O(N)
// SC -> O(1)

