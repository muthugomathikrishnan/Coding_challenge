// Link : https://leetcode.com/problems/count-complete-tree-nodes
// Brute force solution:
// Solution : we can use any travresal to find the nodes count:


class Solution {
private:
    void preorder(TreeNode * root,int &count){
        if(!root) return ;
        count++;
        preorder(root->left,count);
        preorder(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        preorder(root,count);
        return count;
    }
};

// TC -> O(N)
// SC -> O(N)


// our aim is duce the TC 
// TC < O(N)

// It's a complete Tree. So we can use height property : node_count=(2^h)-1
// if it's  a fully complete tree.Then we approach this method.
// but the given input tree some time is not fully completed .
// so we check the any one left or right is fully completed.


class Solution {
private:
    int height_l(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }

    int height_r(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l_height=height_l(root);
        int r_height=height_r(root);
        // (2^h)-1
        if(l_height==r_height) return (1<<l_height)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


//  Best Case TC: O(log n)
// Worst Case TC: O(log² n)
// SC -> we use recursion. so the recursion stack space is : O(long N) . long n->height
