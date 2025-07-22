// link : https://www.geeksforgeeks.org/problems/check-for-bst/1
class Solution {
  bool check(Node * root,int min,int max){
      if(!root) return true;
      if(root->data<min || root->data>max) return 0;      
      return check(root->left,min,root->data-1) && check(root->right,root->data+1,max);
  }
  public:
    bool isBST(Node* root) {
        return check(root,INT_MIN,INT_MAX);
    }
};

// Time Complexity (TC): O(N)
// Space Complexity (SC): O(H)


// Sol 2: Iterative 
class Solution {
  public:
    bool isBST(Node* root) {
        int min=INT_MIN, max=INT_MAX;
        stack<Node*>st;
        Node * curr=root,*prev=nullptr;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr); curr=curr->left;
            }
            
            curr=st.top(); st.pop();
            if(prev && prev->data>=curr->data) return 0;
            prev=curr;
            curr=curr->right;
        }
        return 1;
    }
};

// Time Complexity (TC): O(N)
// Space Complexity (SC): O(H)
