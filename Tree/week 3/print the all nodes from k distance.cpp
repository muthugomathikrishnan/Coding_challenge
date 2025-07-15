// Print all the Nodes at a distance of K in a Binary Tree
// Link :https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Solution 1 : BFS with Parent Tracking - Distance K from Target


class Solution {
private:
    void find_parent(TreeNode *root,unordered_map<TreeNode*, TreeNode*>&parent_track ){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode * curr=q.front();q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    void find_ans(unordered_map<TreeNode*, TreeNode*>&parent_track, TreeNode * target,int k,vector<int>&ans ){
        if(!target) return ;
        unordered_set<TreeNode*>st;
        queue<TreeNode*>q;
        st.insert(target);
        q.push(target);
        int c_level=0;
        while(!q.empty()){
            int s=q.size();
            if(c_level++==k) break;
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();q.pop();
                // left
                if(curr->left && st.find(curr->left)==st.end()){
                    q.push(curr->left);
                    st.insert(curr->left);
                }

                // right

                if(curr->right && st.find(curr->right)==st.end()){
                    q.push(curr->right);
                    st.insert(curr->right);
                }

                // up

                if(parent_track[curr] && st.find(parent_track[curr])==st.end()){
                    q.push(parent_track[curr]);
                    st.insert(parent_track[curr]);
                }
            }
        }

        final_result(q,ans);
    }

    void final_result(queue<TreeNode *>&q,vector<int>&ans){
        while(!q.empty()){
            TreeNode * curr=q.front(); q.pop();
            ans.push_back(curr->val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode* , TreeNode*>parent_track;
        find_parent(root, parent_track);
        vector<int>ans;
        find_ans(parent_track,target,k,ans);
        return ans;
    }
};


// TC -> O(N)
// SC -> O(N)



// Solution 2: dfs 


class Solution {
private:
    void find_parent(TreeNode *node,TreeNode * parent, unordered_map<TreeNode*, TreeNode*>&parent_track ){
        if(!node) return;
        parent_track[node]=parent;
        find_parent(node->left,node,parent_track);
        find_parent(node->right,node,parent_track);
    }

    void find_ans(unordered_map<TreeNode*, TreeNode*>&parent_track,unordered_set<TreeNode*>&st, TreeNode * node,int k,int ds, vector<int>&ans){
        if(!node || st.find(node)!=st.end()) return ;
        st.insert(node);
        if(ds==k){ ans.push_back(node->val); return ;}
        find_ans(parent_track,st,node->left,k,ds+1,ans);
        find_ans(parent_track,st,node->right,k,ds+1,ans);
        find_ans(parent_track,st,parent_track[node],k,ds+1,ans);
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode* , TreeNode*>parent_track;
        find_parent(root,nullptr, parent_track);
        vector<int>ans;
        unordered_set<TreeNode *>st;
        find_ans(parent_track,st,target,k,0,ans);
        return ans;
    }
};


// TC -> O(N)
// SC -> O(N)


