// recursion :
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
};

// Memoization :
class Solution {
private:
    int f(int n, vector<int>&dp){
        if(n==0) return dp[n]=0;
        if(n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};


// Tabulation:

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int>dp(n+1,0);
        dp[0]=0;dp[1]=1;
        for(int i=2;i<=n;i++)   dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};


// Optimal :
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a=0,b=1,c=0;
        int i=2;
        while(i<=n){
            c=a+b;
            a=b;
            b=c;
            i++;
        }
        return c;
    }
};
