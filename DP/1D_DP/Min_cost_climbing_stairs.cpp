// Link

//sol 1: memoization

class Solution {
private:
    int f(int n,vector<int>&cost,vector<int>&dp){
        if(n==0) return dp[0]=cost[0];
        if(n==1) return dp[1]=cost[1];
        if(dp[n]!=-1) return dp[n];
        int jump1=f(n-1,cost,dp)+cost[n];
        int jump2=f(n-2,cost,dp)+cost[n];
        return dp[n]=min(jump1,jump2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(cost.size()-1,cost,dp), f(cost.size()-2,cost,dp));
    }
};


// Tabulation : TC ->O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,0);
        dp[0]=cost[0];dp[1]=cost[1];
        for(int i=2;i<n;i++)
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        return min(dp[n-1],dp[n-2]);
    }
};


// Optimization 

