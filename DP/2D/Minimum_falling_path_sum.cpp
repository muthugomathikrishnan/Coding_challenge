// Link :https://leetcode.com/problems/minimum-falling-path-sum/submissions/1730757984/?envType=study-plan-v2&envId=dynamic-programming

// Sol 1 : memoization

class Solution {
private:
    int f(int m,int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return dp[0][j]=matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+f(m,i-1,j,matrix,dp);
        int l_d=matrix[i][j]+f(m,i-1,j-1,matrix,dp);
        int r_d=matrix[i][j]+f(m,i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(l_d,r_d));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=1e9;
        for(int i=n-1;i>=0;i--) ans=min(ans,f(n,n-1,i,matrix,dp));
        return ans;
    }
};

// Tabulation :
