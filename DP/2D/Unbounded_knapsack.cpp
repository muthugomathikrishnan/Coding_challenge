// Link : https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?leftPanelTabValue=SUBMISSION
int f(int ind, vector<int>&profit,vector<int>&weight,int w,vector<vector<int>>&dp){
    if(ind==0) return (w/weight[ind])*profit[ind];
    if(dp[ind][w]!=-1) return dp[ind][w];
    int not_take=0+f(ind-1,profit,weight,w,dp);
    int take=-1e9;
    if(weight[ind]<=w) take=profit[ind]+f(ind,profit,weight,w-weight[ind],dp);
    return dp[ind][w]=max(take,not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,profit,weight,w,dp);
}
