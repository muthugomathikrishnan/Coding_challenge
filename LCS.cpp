// LCS : https://leetcode.com/problems/longest-common-subsequence/ 

// Solution 1: recursion 
class Solution {
    int f(string s1,string s2,int ind1,int ind2){
        if(ind1<0 || ind2<0) return 0;
        if(s1[ind1]==s2[ind2]) return 1+f(s1,s2,ind1-1,ind2-1);
        return max(f(s1,s2,ind1-1,ind2),f(s1,s2,ind1,ind2-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size()-1,n2=text2.size()-1;
        return f(text1,text2,n1,n2);
    }
};

// TC -> O(2^(n1+n2))
// SC -> O(n1+n2)

// Solution 1: memoization is used to store the results of subproblems, 
//which helps avoid recomputation in recursion. 
//This optimization transforms an exponential time recursive solution into a polynomial time dynamic programming solution.

class Solution {
    int f(string s1,string s2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=0) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+f(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        return f(text1,text2,n1-1,n2-1,dp);
    }
};

// TC-> O(n1 * n2)
// SC ->O(n1 * n2) + RSS: O(n1+n2)



// Solution 3 : tabulation 

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};
// TC-> O(n1 * n2)
// SC ->O(n1 * n2)



// Solution 4: Space optimization :
// covert 2d array into 1 d array

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

// TC -> O(n1 * n2)
// SC -> O(n2)


