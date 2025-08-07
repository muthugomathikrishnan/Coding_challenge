// Link : https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=dynamic-programming

// Sol 1 : memoization
class Solution {
private:
    int f(int n, vector<int>&dp){
        if(n==0) return dp[n]=0;
        if(n==1 || n==2) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp)+f(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};

// Sol 2: Tabulation

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        vector<int>dp(n+1,0);
        dp[0]=0;dp[1]=1;dp[2]=1;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};


// Sol 3: optimal sol

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int a=0,b=1,c=1,d=0;
        int i=3;
        while(i<=n){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            i++;

        }
        return d;
    }
};
