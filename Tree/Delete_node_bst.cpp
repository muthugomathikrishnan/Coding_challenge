// Link :https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1

// Sol : 
class Solution {
  private:
    int find_min(Node * root){
        while(root && root->left) root=root->left;
        return root->data;
    }
  public:
    
    Node *deleteNode(Node *root, int x) {
        if(!root) return NULL;
        
        if(root->data< x) root->right=deleteNode(root->right,x);
        else if(root->data> x) root->left=deleteNode(root->left,x);
        
        else {
        // No child 
        if(!root->left && !root->right) {delete root; return NULL;}
        
        // One child
        if(!root->left){
            Node * temp=root->right;
            delete root;
            return temp;
        }
        
        if(!root->right){
            Node * temp=root->left;
            delete root;
            return temp;
        }
        
        // Two child 
        int mini=find_min(root->right);
        root->data=mini;
        root->right=deleteNode(root->right, mini);
        }
        return root;
    }
};

/*

Time Complexity (TC): O(h)
Space Complexity (SC): O(h) (due to recursion stack)

Where h is the height of the BST.

In a balanced BST, h = log n

In a skewed BST, h = n
*/
