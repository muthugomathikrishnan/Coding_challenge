// Link : https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

class Solution {
  private:
    int f(int ind,int buy, int c,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(ind==n || c==0) return 0;
        if(dp[ind][buy][c]!=-1) return dp[ind][buy][c];
        int profit=0;
        if(buy==0) profit=max(0+f(ind+1,0,c,prices,dp),-prices[ind]+f(ind+1,1,c,prices,dp));
        else profit=max(0+f(ind+1,1,c,prices,dp),prices[ind]+f(ind+1,0,c-1,prices,dp));
        return dp[ind][buy][c]=profit;
    }
  public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,2,prices,dp);
    }
};
