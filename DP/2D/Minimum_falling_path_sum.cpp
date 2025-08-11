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
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int dir=(j<n-1) ? dp[i-1][j+1]+ matrix[i][j] : INT_MAX;
                int dil=(j>0) ? dp[i-1][j-1] + matrix[i][j] : INT_MAX;
                int up=dp[i-1][j]+matrix[i][j];
                dp[i][j]=min(up,min(dir,dil));
                }
        }
        int res=dp[m-1][0];
        for(int j=0;j<n;j++){
             res=min(res,dp[m-1][j]);
        }
        return res;
    }
};


// Optimal :
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        vector<int>prev(n,0),curr(n,0);
        for(int i=0;i<n;i++) prev[i]=matrix[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int dir=(j<n-1) ? prev[j+1]+ matrix[i][j] : INT_MAX;
                int dil=(j>0) ? prev[j-1] + matrix[i][j] : INT_MAX;
                int up=prev[j]+matrix[i][j];
                curr[j]=min(up,min(dir,dil));
                }
                prev=curr;
        }
        int res=prev[0];
        for(int j=0;j<n;j++){
             res=min(res,prev[j]);
        }
        return res;
    }
};
