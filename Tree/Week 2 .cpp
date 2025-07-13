 

// Morris Inorder traversal :

//It based on thread connection:

  

vector<int> getInOrderTraversal(TreeNode *root)

{

    TreeNode* curr= root;

    vector<int>Inorder;

  

    while(curr){

        if(!curr->left){ Inorder.push_back(curr->data); curr=curr->right;}

  

        else {

            TreeNode * prev=curr->left;

            while(prev->right && prev->right!=curr) prev=prev->right;

  

            if(!prev->right) {prev->right=curr; curr=curr->left;}

            else {prev->right=NULL; Inorder.push_back(curr->data); curr=curr->right;}

        }

    }

    return Inorder;

}
// TC -> O(N);
// SC -> O(1);

  // In pre_order :


else {

            TreeNode * prev=curr->left;

            while(prev->right && prev->right!=curr) prev=prev->right;

  

            if(!prev->right) {prev->right=curr; Inorder.push_back(curr->data); curr=curr->left;}

            else {prev->right=NULL; curr=curr->right;}

        }
 
 
// Tree to LL:
// Recursion :


  

class Solution {

public:

    TreeNode * prev=NULL;

    void flatten(TreeNode* root) {

        if(!root) return;

        flatten(root->right);

        flatten(root->left);

        root->right=prev;

        root->left=NULL;

        prev=root;

    }

};
// TC -> O(N)
// SC -> O(N)


//  iterative method :

  

class Solution {

public:

    TreeNode * prev=NULL;

    void flatten(TreeNode* root) {

        if(!root) return;

        stack<TreeNode *>st;

        st.push(root);

        while(!st.empty()){

            TreeNode * curr=st.top();

            st.pop();

            if(curr->right) st.push(curr->right);

            if(curr->left) st.push(curr->left);

            curr->left=NULL;

            if(!st.empty()) curr->right=st.top();

        }

    }
};
// TC -> O(N)
// SC -> O(N)


// Morris traversal method:


  

class Solution {

public:

    TreeNode * prev=NULL;

    void flatten(TreeNode* root) {

        if(!root) return;

        TreeNode* curr=root;

  

        while(curr){

            if(curr->left){

                TreeNode* prev=curr->left;

                while(prev->right && prev->right!=curr)

                    prev=prev->right;

                prev->right=curr->right;

                curr->right=curr->left;

                curr->left=NULL;

            }

            curr=curr->right;

        }        

  }
};

// TC -> O(N)
// SC -> O(1)


// LCA :

// Brute force approach :

class Solution {
private:

    bool getpath(TreeNode * root, int v, vector<TreeNode *>&arr){

        if(!root) return false;

        arr.push_back(root);

        if(root->val==v) return true;

        if(getpath(root->left,v,arr) || getpath(root->right,v,arr)) return true;

        arr.pop_back();

        return false;

    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>path_p,path_q;

        getpath(root,p->val,path_p);

        getpath(root,q->val,path_q);

        int i=0;

        while(i<path_p.size() && i<path_q.size() && path_p[i]==path_q[i]) i++;

        return path_p[i-1];

    }

};

// TC -> O(N) + O(N)
// SC -> O(N) + O(N)


 
// Optimal solution:

  

class Solution {

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || root==p || root==q) return root;

        TreeNode * left=lowestCommonAncestor(root->left,p,q);

        TreeNode * right=lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;

        return right ? right : left;

    }

};

// TC -> O(N)
// SC -> O(N)


// Max width of Tree:


class Solution {

public:

    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;

        queue<pair<TreeNode*,long long>>q;

        q.push({root,0});

        long long ans=0;

        while(!q.empty()){

            int s=q.size();

            long long m=q.front().second;

            long long first=0,last=0;

            for(int i=0;i<s;i++){

                long long id=q.front().second-m;

                TreeNode * curr=q.front().first;

                q.pop();

  

                if(i==0) first=id;

                if(i==s-1) last=id;

                if(curr->left) q.push({curr->left, 2*id+1});

                if(curr->right) q.push({curr->right, 2*id+2});

            }

            ans=max(ans,last-first+1);

        }

        return ans;

    }

};


// Root - some child:

  

class Solution {

public:

    bool checkTree(TreeNode* root) {

       if(!root)  return true;

       return root->val==root->left->val + root->right->val;        

    }

};



// children-sum-parent:
 
class Solution {
  public:
    int isSumProperty(Node *root) {
        if(!root) return 1;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node * curr=q.front();
            q.pop();
            
            if(!curr->left && !curr->right) continue;
            int child_sum=0;
            
            if(curr->left){
                child_sum+=curr->left->data;
                q.push(curr->left);
            }
            
            if(curr->right){
                child_sum+=curr->right->data;
                q.push(curr->right);
            }
            
            if(child_sum !=curr->data) return 0;
        }
        return 1;
    }
};

