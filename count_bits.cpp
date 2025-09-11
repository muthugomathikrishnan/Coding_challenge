// Link :
 // Brute force 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            int x=i,cnt=0;
            while(x){
                cnt+=(x&1);
                x>>=1;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};

// Dp :
#include <bits/stdc++.h> 
int f(int x,vector<int>&dp){
	if(x==0) return 0;
	if(dp[x]!=-1) return dp[x];
	return dp[x]=(x&1)+f(x>>1,dp);
}
vector<int> count(int N)
{
	vector<int>dp(N+1,-1);
	dp[0]=0;
	vector<int>ans(N+1,0);
	for(int i=0;i<=N;i++){
		ans[i]=f(i,dp);
	}
	return ans;
}
