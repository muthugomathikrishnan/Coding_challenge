// Link : https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
bool dfs(int node,vector<int>&visit,vector<int>&path_v, vector<int>adj[]){
  visit[node]=1;
  path_v[node]=1;
  for(auto it : adj[node]){
    if(!visit[it]){
      if(dfs(it,visit,path_v,adj)) return true;
    }
    else if(path_v[it]==1) return true;
  }
  path_v[node]=0;

  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int>adj[n];
  for(auto e : edges) adj[e.first-1].push_back(e.second-1);
  vector<int>visit(n,0),path_v(n,0);
  for(int i=0;i<n;i++){
    if(!visit[i]){
      if(dfs(i,visit,path_v,adj)) return 1;
    }
  }
  return 0;
}
