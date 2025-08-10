// Link :
// Sol 1 : memoization
class Solution {
private:
    int f(int i, int j,int n, vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==n-1) return dp[i][j]=triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+f(i+1,j,n,triangle,dp);
        int dia=triangle[i][j]+f(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(down,dia);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,n,triangle,dp);
    }
};

// Tabulation :
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int up=triangle[i][j]+dp[i+1][j];
                int di=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(up,di);
            }
        }
        return dp[0][0];
    }
};

// optimal:

class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>front(n,0),cur(n,0);
        for(int i=0;i<n;i++) front[i]=triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int up=triangle[i][j]+front[j];
                int di=triangle[i][j]+front[j+1];
                cur[j]=min(up,di);
            }
            front=cur;
        }
        return front[0];
    }
};
