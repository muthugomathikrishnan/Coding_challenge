// Link :

// Sol 1:
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int m=s1.length(), n=s2.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
        
    }
};


// Memoization
class Solution {
private:
    int f(int n, int m ,string s1, string s2,vector<vector<int>>&dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]) return dp[n][m]= 1+f(n-1,m-1,s1,s2,dp);
        return dp[n][m]=max(f(n-1,m,s1,s2,dp),f(n,m-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return f(n1,n2,s1,s2,dp);
    }
};


// Optimal :

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int>prev(n2+1,0);
        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
};

// 
