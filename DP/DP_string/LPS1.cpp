// Link :https://leetcode.com/problems/longest-palindromic-subsequence/submissions/1383773401/?envType=study-plan-v2&envId=dynamic-programming
class Solution {
public:
    int f(int left,int right,string &s,vector<vector<int>>&dp){
        if(left>right) return 0;
        if(left==right) return 1;
        if(dp[left][right]!=-1) return dp[left][right];
        if(s[left]==s[right]) return dp[right][left]=2+f(left+1,right-1,s,dp);
        return dp[left][right]=max(f(left+1,right,s,dp),f(left,right-1,s,dp));
    
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }
};
