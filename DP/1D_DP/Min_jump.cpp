// Link : https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution {
  private:
    int f(int i,vector<int>&arr,vector<int>&dp){
        if(i>=arr.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int j=i+1;j<=arr[i]+i;j++){
            int val=f(j,arr,dp);
            if(val !=INT_MAX) ans=min(ans,val+1);
        }
        return dp[i]=ans;
    }
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size()-1;
        vector<int>dp(n,-1);
        int ans= f(0,arr,dp);
        return (ans==INT_MAX) ? -1 :ans;
    }
};
