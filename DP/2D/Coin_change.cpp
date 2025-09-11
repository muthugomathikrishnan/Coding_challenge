// Link : https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
long f(int ind,int *denominations,int target,vector<vector<long>>&dp){
    if(ind==0) return (target%denominations[ind]==0);
    if(dp[ind][target]!=-1) return dp[ind][target];
    long not_take=f(ind-1,denominations,target,dp);
    long take=0;
    if(denominations[ind]<=target) take=f(ind,denominations,target-denominations[ind],dp);
    return dp[ind][target]=not_take+take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{   vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return f(n-1,denominations,value,dp);
}
