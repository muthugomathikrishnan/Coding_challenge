// sol 1 :Brute force approach


class Solution {
  private:
    bool isValid(Node*root, int min_v, int max_v ){
        if(!root) return true;
        if(root->data>=max_v || root->data<=min_v) return false;
        return isValid(root->left,min_v,root->data) && isValid(root->right,root->data,max_v);
    }
    int isSize(Node* root){
        if(!root) return 0;
        return 1+isSize(root->left)+isSize(root->right);
    }
  public:
   
    int largestBst(Node *root) {
        if(!root) return 0;
        if(isValid(root,INT_MIN,INT_MAX)) return isSize(root);
        return max(largestBst(root->left),largestBst(root->right));
    }
}; 


// Time Complexity (TC): O(N²)
// Space Complexity (SC): O(H)
