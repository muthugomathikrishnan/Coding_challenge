// Link :https://www.geeksforgeeks.org/problems/coin-change2448/1
class Solution {
  private:
    int f(int ind,int sum,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0) return dp[ind][sum]=(sum%coins[0]==0);
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int not_take=f(ind-1,sum,coins,dp);
        int take=0;
        if(coins[ind]<=sum) take=f(ind,sum-coins[ind],coins,dp);
        return dp[ind][sum]=take+not_take;
        
    }
  public:
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,coins,dp);
        }
};
