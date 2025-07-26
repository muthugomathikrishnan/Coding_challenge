// memoization :
class Solution {
    int f1(int n , vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f1(n-1,dp)+f1(n-2,dp);
    }
  public:
    int nthFibonacci(int n) {
        if(n<=1) return n;
        vector<int>dp(n+1,-1);
        return f1(n,dp);
        
    }
};

// TC -> O(N)
// SC -> O(N)

// Tabulation :
class Solution {
  public:
    int nthFibonacci(int n) {
        if(n<=1) return n;
        vector<int>dp(n+1,0);
        dp[1]=dp[2]=1;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
        
    }
};

// TC -> O(N)
// SC -> O(N)

// Optimal solution :

// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        if(n<=1) return n;
        int a=1,b=1,c,i=3;
        while(i<=n){c=a+b;a=b;b=c;i++;}
        return b;
        
    }
};
