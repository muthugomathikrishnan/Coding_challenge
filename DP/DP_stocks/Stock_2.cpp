// Link :
// Sol 1:


class Solution {
  private:
    int f(int i,int n,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy==0)
            profit=max(0+f(i+1,n,0,prices,dp),-prices[i]+f(i+1,n,1,prices,dp));
        else
            profit=max(0+f(i+1,n,1,prices,dp),prices[i]+f(i+1,n,0,prices,dp));
        return dp[i][buy]=profit;
    }
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,n,0,prices,dp);
        
    }
};

// Sol_2

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0) profit=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]);
                else profit=max(0+dp[i+1][1],prices[i]+dp[i+1][0]);
                dp[i][j]=profit;
            }
            
        }
        return dp[0][0];
    }
};
