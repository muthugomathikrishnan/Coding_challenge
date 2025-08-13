// Link :

// Sol 1:
class Solution {
private:
    int f(int ind,int n,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int not_take=0+f(ind+1,n,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
            take=1+f(ind+1,n,ind,nums,dp);
        return dp[ind][prev+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n,-1,nums,dp);
    }
};

// Sol 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
