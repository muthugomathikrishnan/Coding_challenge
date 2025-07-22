// recursion : min
class Solution {
    
    int min_f(Node *root){
        if(!root) return INT_MAX;
        int res=root->data;
        int left=min_f(root->left);
        int right=min_f(root->right);
        
        if(res>left) res=left;
        if(res>right) res=right;
        return res;
    }
  public:
    int minValue(Node* root) {
        return min_f(root);
    }
};


//iteration :

class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return 0;
        while(root->left) root=root->left;
        return root->data;
    }
};


// Max_max  :

class Solution {
  public:
    int findMin(Node *root) {
        if(!root) return 0;
        while(root->left) root=root->left;
        return root->data;
    }

    int findMax(Node *root) {
        if(!root) return 0;
        while(root->right) root=root->right;
        return root->data;
    }
};

