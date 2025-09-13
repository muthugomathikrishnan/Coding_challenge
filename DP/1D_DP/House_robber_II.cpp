// Link https://leetcode.com/problems/house-robber-ii/submissions/1768879638/?envType=problem-list-v2&envId=50vif4uc
class Solution {

int f(int ind,vector<int>&nums,vector<int>&dp){
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    if(ind==0) return nums[ind];
    int not_take=f(ind-1,nums,dp);
    int take=f(ind-2,nums,dp)+nums[ind];
    return dp[ind]=max(take,not_take); 
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        int ans1= f(n-2,nums,dp1);
        nums.erase(nums.begin());
        vector<int>dp2(n,-1);    
        int ans2=f(n-2,nums,dp2);
        return max(ans1,ans2);
    }
};
