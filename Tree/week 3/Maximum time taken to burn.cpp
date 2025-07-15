// Q 2 : Minimum time taken to BURN the Binary Tree from a Node
// Link : https://www.geeksforgeeks.org/problems/burning-tree/1

// Solution 1 : BFS 
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    void find_parent(Node * node , Node* parent,unordered_map<Node*,Node*>&parent_track){
        if(!node) return;
        parent_track[node]=parent;
        find_parent(node->left,node,parent_track);
        find_parent(node->right,node,parent_track);
    }
    
    Node *find_target(Node * root,int target){
        if(!root) return nullptr;
        if(root->data==target) return root;
        
        Node * left=find_target(root->left,target);
        Node *right=find_target(root->right,target);
        return left ? left :right;
    }
    
    int find_max(unordered_map<Node*,Node*>&parent_track,unordered_set<Node*>&visit,Node* target){
        queue<Node*>q;
        q.push(target);
        visit.insert(target);
        int dis=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node * curr=q.front(); q.pop();
                // left
                
                if(curr->left && visit.find(curr->left)==visit.end()){
                    q.push(curr->left);
                    visit.insert(curr->left);
                }
                
                // right
                
                if(curr->right && visit.find(curr->right)==visit.end()){
                    q.push(curr->right);
                    visit.insert(curr->right);
                }
                
                // up
                
                if(parent_track[curr] && visit.find(parent_track[curr])==visit.end()){
                    q.push(parent_track[curr]);
                    visit.insert(parent_track[curr]);
                }
            }
            dis++;
        }
        return dis-1;
    }
  public:
    int minTime(Node* root, int target) {
        if(!root) return 0;
        unordered_map<Node*, Node*>parent_track;
        find_parent(root,nullptr,parent_track);
        Node *tar=find_target(root,target);
        unordered_set<Node *>visit;
        int dis=find_max(parent_track,visit,tar);
        return dis;
    }
};

// TC -> O(N)
// SC -> O(N)
