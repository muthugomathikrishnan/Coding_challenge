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
