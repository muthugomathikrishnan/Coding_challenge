// Link :

// Sol1 : using recursion 
class Solution {
  public:
    int countWays(int n) {
        if(n<=1) return 1;
        return countWays(n-1)+countWays(n-2);
        
    }
};

// TC -> O(2 ^ n)
// SC -> O(n)

// Using Memoization :
class Solution {
  private:
        int Count(int n, vector<int>&dp){
            if(n<=1) return 1;
            if(dp[n]!=-1) return dp[n];
            return dp[n]=Count(n-1,dp)+Count(n-2,dp);
        }
  public:
    int countWays(int n) {
        if(n<=1) return 1;
        vector<int>dp(n,-1);
        return Count(n,dp);
        
    }
};


// TC -> O(N)
// SC -> O(N)


// Optimal Solution :
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int a=1,b=1;
        int i=3;
        int c=a+b;
        while(i<=n){
            a=b;
            b=c;
            c=a+b;
            i++;
        }
        return c;
    }
};


// TC -> O(N)
// SC -> O(1)
