// Memoization : https://leetcode.com/problems/climbing-stairs/
class Solution {
    int Tot(int n ,vector<int>&nums){
        if(n==0 || n==1) return 1;
        if(nums[n]!=-1) return nums[n];
        return nums[n]=Tot(n-1,nums)+Tot(n-2,nums);
    }
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        vector<int>nums(n+1,-1);
        return Tot(n,nums);
    }
};

// TC -> O(N)
// SC -> O(N)


// Tabulation :
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        vector<int>nums(n+1,0);
        nums[0]=nums[1]=1;
        for(int i=2;i<=n;i++) nums[i]=nums[i-1]+nums[i-2];
        return nums[n];
    }
};

// TC -> O(N)
// SC -> O(N)


// Optimal Solution:

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
// SC -> O(N)
