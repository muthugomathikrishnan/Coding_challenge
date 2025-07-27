// Link :https://leetcode.com/problems/binary-search-tree-iterator/submissions/1712924425/

// Solution :

class BSTIterator {
private: 
    stack<TreeNode *>st;
    void pushAll(TreeNode * root){
        while(root){
            st.push(root); root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
     pushAll(root);   
    }
    
    int next() {
        TreeNode * node=st.top(); st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


// TC -> O(1)
// SC -> O(H)
