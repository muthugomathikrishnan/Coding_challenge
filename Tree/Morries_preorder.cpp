// Similar logic, push value before moving left
if (!curr->left) {
    Inorder.push_back(curr->data);
    curr = curr->right;
} else {
    TreeNode* prev = curr->left;
    while (prev->right && prev->right != curr) prev = prev->right;

    if (!prev->right) {
        prev->right = curr;
        Inorder.push_back(curr->data);  // Push before going left (preorder)
        curr = curr->left;
    } else {
        prev->right = NULL;
        curr = curr->right;
    }
}

