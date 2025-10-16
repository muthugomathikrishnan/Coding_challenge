// Link :
#include <bits/stdc++.h> 
void dfs(int node,vector<int>&visit,vector<vector<int>>&adj,stack<int>&st){
    visit[node]=1;
    for(auto it : adj[node]){
        if(!visit[it]) dfs(it,visit,adj,st);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>>adj(v);
    for(auto e: edges) adj[e[0]].push_back(e[1]);
    stack<int>st;
    vector<int>visit(v,0);
    for(int i=0;i<v;i++){
        if(!visit[i]) dfs(i,visit,adj,st);
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
