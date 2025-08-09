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

// Sol 2 :
class Solution { 
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ 
                if(i==0 && j==0) dp[0][0]=1;
                else {
                int right=0,down=0;
                if(i>=1) down+=dp[i-1][j];
                if(j>=1) right+=dp[i][j-1];
                dp[i][j]=right+down;
            }
            }
        }
        return dp[m-1][n-1];
    }
};
