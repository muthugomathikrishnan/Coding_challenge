// Link :https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1



class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *x) {
        int success=-1;
        while(root){
            if(x->data>=root->data) root=root->right;
            else {
                success=root->data;
                root=root->left;
            }
        }
        return success;
    }
};

// TC -> O(H)
// SC -> O(1)
