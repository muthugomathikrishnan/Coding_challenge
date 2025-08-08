// Link :https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=dynamic-programming

// Sol 1 : memoization
class Solution {
private:
    int f(int m,int n,vector<vector<int>>&dp){
        if(m==1 && n==1) return dp[m][n]=1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=f(m-1,n,dp) +f(m,n-1,dp);
    }   
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,dp);
    }
};

