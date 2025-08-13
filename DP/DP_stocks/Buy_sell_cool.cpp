// Sol 
class Solution {
  private:
    long long getAns(int ind,int buy, vector<long long>&prices,int n,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==0)
            profit=max(0+getAns(ind+1,0,prices,n,dp),-prices[ind]+getAns(ind+1,1,prices,n,dp));
        else 
            profit=max(0+getAns(ind+1,1,prices,n,dp),prices[ind]+getAns(ind+2,0,prices,n,dp));
        return dp[ind][buy]=profit;
    }
    
  public:
    long long maximumProfit(vector<long long>& prices, int n) {
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return getAns(0,0,prices,n,dp);
    }
};
