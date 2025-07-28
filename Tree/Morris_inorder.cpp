vector<int> getInOrderTraversal(TreeNode *root) {
    TreeNode* curr = root;
    vector<int> Inorder;

    while (curr) {
        if (!curr->left) {
            Inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr) prev = prev->right;

            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                Inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return Inorder;
}
// TC -> O(N)
// SC -> O(1)
