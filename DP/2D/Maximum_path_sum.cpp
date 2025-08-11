// Sol 
// User function Template for C++

class Solution {
  private:
    int f(int i,int j,int m,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(j<0 || j>=m) return -1e9;
        if(i==0) return dp[i][j]=mat[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=mat[i][j]+f(i-1,j,m,mat,dp);
        int dir=mat[i][j]+f(i-1,j+1,m,mat,dp);
        int dil=mat[i][j]+f(i-1,j-1,m,mat,dp);
        return dp[i][j]=max(up,max(dir,dil));
    } 
  public:
    int maximumPath(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=-1e9;
        for(int j=m-1;j>=0;j--) ans=max(ans,f(n-1,j,m,mat,dp));
        return ans;
            
        
    }
};
