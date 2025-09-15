// Link :https://www.naukri.com/code360/problems/minimum-knight-moves_2179628?leftPanelTabValue=SOLUTION
#include<bits/stdc++.h>
int minimumKnightMoves(int x, int y) {
    x=abs(x);
    y=abs(y);
    queue<pair<int,int>>q;
    map<pair<int,int>,int>dist;
    q.push({0,0});
    dist[{0,0}]=0;
    int d_r[]={1,2,1,2,-1,-2,-2,-1};
    int d_c[]={2,1,-2,-1,2,1,-1,-2};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(it.first==x && it.second==y) return dist[{it.first,it.second}];
        for(int i=0;i<8;i++){
            int n_r=d_r[i]+it.first;
            int n_c=d_c[i]+it.second;
            if(n_r>=-2 && n_c>=-2 && n_r<=x+2 && n_c<=y+2){
                if(!dist.count({n_r,n_c})){
                    dist[{n_r,n_c}]=dist[{it.first,it.second}]+1;
                    q.push({n_r,n_c});
                }
            }
        }
    }
    return -1;
}

