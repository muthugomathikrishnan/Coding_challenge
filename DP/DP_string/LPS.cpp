// Link :
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string s1=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ind=dp[n][n]-1;
        int i=n,j=n;
        string ans="";
        for(int i=0;i<dp[n][n];i++) ans+="$";
        while(i>0 && j>0){
            if(s1[i-1]==s[j-1]){
                ans[ind]=s1[i-1];
                i--;
                j--;
                ind--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }   
        return ans;

    }
};
