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


// Optimal sol
class Nodeval{
    public:
    int min_v,max_v,size;
    Nodeval(int mini,int maxi,int s){
        this->min_v=mini;
        this->max_v=maxi;
        this->size=s;
    }
};

class Solution {
private:
    Nodeval bsthelper(Node* root) {
        if(!root) return Nodeval(INT_MAX,INT_MIN,0);
        auto left=bsthelper(root->left);
        auto right=bsthelper(root->right);
        
        if(left.max_v<root->data && root->data<right.min_v)
            return Nodeval(min(left.min_v,root->data),max(right.max_v,root->data),left.size+right.size+1);
        return Nodeval(INT_MIN,INT_MAX,max(left.size,right.size));
    }

public:
    int largestBst(Node* root) {
        return bsthelper(root).size;
    }
};


// TC -> O(N)
// SC -> O(1)
