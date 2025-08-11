// Link :https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// User function template for C++

class Solution {
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
        return dp[n][m];
        
    }
};
