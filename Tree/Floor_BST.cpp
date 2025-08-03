// Link :https://www.geeksforgeeks.org/problems/floor-in-bst/1

// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        int flr=-1;
        
        while(root){
            if(root->data==x) return root->data;
            if(root->data<x){flr=root->data; root=root->right;}
            else root=root->left;
        }
        return flr;
    }
};

// TC -> O( Log N)
// SC -> O(1)
