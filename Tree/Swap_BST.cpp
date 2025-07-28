// Link : https://leetcode.com/problems/recover-binary-search-tree/
// Sol 1: Inorder Traversal

class Solution {
private:
    TreeNode * first=NULL;
    TreeNode * second=NULL;
    TreeNode * prev=NULL;
    
    void Inorder(TreeNode * root){
        if(!root) return ;
        Inorder(root->left);
        if(prev && prev->val>root->val){
            if(!first) first=prev;
            second=root;
        }
        prev=root;
        Inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        Inorder(root);
        swap(first->val,second->val);
        
    }
};

// TC -> O(N)
// SC -> O(N)


// Sol 2 : Morries Traversal


class Solution {

public:
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        TreeNode * first=NULL;
        TreeNode * second=NULL;
        TreeNode * prev=NULL;
        TreeNode * curr=root;

        while(curr){
            if(curr->left){
                TreeNode * p=curr->left;
                while(p->right && p->right!=curr) p=p->right;

                if(!p->right){ p->right=curr;curr=curr->left;}

                else {
                    p->right=NULL;
                    if(prev && prev->val>curr->val){
                        if(!first) first=prev;
                        second=curr;
                    }
                    prev=curr;
                    curr=curr->right;
                }

            }

            else {
                if(prev &&  prev->val>curr->val){
                    if(!first) first=prev;
                    second=curr;
                }
                prev=curr;
                curr=curr->right;
            }
        }

        if(first && second) swap(first->val,second->val);    
    }
};


// TC -> O(N)
// SC -> O(1)
