// Link :https://leetcode.com/problems/distinct-subsequences/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
  private :
    int f(int i,int j,string& txt,string &pat,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(txt[i]==pat[j]) return dp[i][j]=f(i-1,j-1,txt,pat,dp)+f(i-1,j,txt,pat,dp);
        return dp[i][j]=f(i-1,j,txt,pat,dp);
    }  
  
  public:
    int subseqCount(string &txt, string &pat) {
        int i=txt.length(),j=pat.length();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(i-1,j-1,txt,pat,dp);
    }
};

// Tabulation :
class Solution {
    int p=1e9+7;
public:
    int numDistinct(string s, string t) {
        int n1=s.size(),n2=t.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++) dp[i][0]=1;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])% p;
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n1][n2];
    }
};
