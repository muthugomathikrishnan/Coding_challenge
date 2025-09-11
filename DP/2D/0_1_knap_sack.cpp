// Link : https://www.naukri.com/code360/problems/0-1-knapsack_1072980?leftPanelTabValue=SUBMISSION
int f(int ind,vector<int>&values,vector<int>&weights,int w,vector<vector<int>>&dp){
	if(ind==0){
		if(weights[ind]<=w) return values[0];
		return 0;
	}
	if(dp[ind][w]!=-1) return dp[ind][w];
	int not_take=f(ind-1,values,weights,w,dp)+0;
	int take=-1e9;
	if(weights[ind]<=w) take=f(ind-1,values,weights,w-weights[ind],dp)+values[ind];
	return dp[ind][w]=max(take,not_take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return f(n-1,values,weights,w,dp);
}
