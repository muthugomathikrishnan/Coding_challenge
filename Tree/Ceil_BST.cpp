// Link : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int findCeil(Node* root, int input) {
    if(!root) return -1;
    int c=-1;
    while(root){
        if(root->data==input) return c=root->data;
        if(root->data<input) root=root->right;
        else {
            c=root->data;
            root=root->left;
        }
    }
    return c;
    
}

// TC -> O(N)
// SC -> O(1)
