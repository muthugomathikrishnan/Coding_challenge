// Link : https://www.naukri.com/code360/problems/bipartite-graph_1062589


#include <bits/stdc++.h> 
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
    color[node] = col;
    for (auto it : adj[node]) {
        if (color[it] == -1) {
            if (!dfs(it, !col, color, adj)) 
                return false;
        } 
        else if (color[it] == col) 
            return false;
    }
    return true; 
}

bool isBipartite(vector<vector<int>>& graph, int v, int e) {
    vector<vector<int>> adj(v);
    
    for (int i = 0; i < e; i++) {
        int u = graph[i][0];
        int w = graph[i][1];
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    vector<int> color(v, -1);
    for (int i = 0; i < v; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, color, adj)) 
                return false;
        }
    }
    return true;
}


