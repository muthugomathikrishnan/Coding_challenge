// Link :

// Sol 1 : memoization

class Solution {
private:
    int f(int n, int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(n==0 && m==0) return dp[0][0]=grid[0][0];
         if(n<0 || m<0) return 1e9;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=min(f(n-1,m,grid,dp),f(n,m-1,grid,dp))+grid[n][m];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};

// Sol 2: Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else {
                    int left=INT_MAX,right=INT_MAX;
                    if(j>0) right=dp[i][j-1]+grid[i][j];
                    if(i>0) left=dp[i-1][j]+grid[i][j];
                    dp[i][j]=min(right,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// Optimal 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() ;
        int n=grid[0].size();
        vector<int>prev(n,0),curr(n,0);
        int right=INT_MAX,down=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0 ) {
                    prev[j]=grid[i][j];
                    curr[j]=grid[i][j];
                    }
                else {
                    if(j>0) right= curr[j-1];
                    if(i>0) down=prev[j];
                    curr[j]=min(down,right)+grid[i][j];
              }
                }
                prev=curr;
                }

        
    return prev[n-1];
    }
    
};
