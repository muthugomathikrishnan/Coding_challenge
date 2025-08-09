// Link :https://leetcode.com/problems/unique-paths-ii/?envType=study-plan-v2&envId=dynamic-programming

// Sol 1:
class Solution {
private:
    int f(int n,int m,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(n==0 && m==0 && obstacleGrid[n][m]!=1) return dp[n][m]=1;
        if(n<0 || m<0 ) return 0;
        if(n>=0 && m>=0 && obstacleGrid[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=f(n-1,m,obstacleGrid,dp);
        int down=f(n,m-1,obstacleGrid,dp);
        return dp[n][m]=up+down;
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
};
