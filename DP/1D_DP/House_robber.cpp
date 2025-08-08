// Link 


// Sol 1: Memoization
class Solution {
private:
    int f(int n,vector<int>&nums,vector<int>&dp){
        if(n==0) return dp[0]=nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=f(n-2,nums,dp)+nums[n];
        int not_pick=f(n-1,nums,dp)+0;
        return dp[n]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
       if(n==0) return nums[0];
       return f(n-1,nums,dp); 
    }
};


// Sol 2: Tabulation:
class Solution {

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;       
        if(n==1) return nums[0];
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }Q
       return dp[n-1]; 
    }
};


// Optimal:
class Solution {

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;       
        if(n==1) return nums[0];
        int prev2=nums[0],prev1=max(nums[1],prev2),curr;
        int i=2;
        while(i<n){
            curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
            i++;
        } 
        return prev1;
    }
};
