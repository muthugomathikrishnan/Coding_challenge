// Sol 
class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),c(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        c[i]=c[j];
                    }
                    else if(dp[i]==dp[j]+1) c[i]+=c[j];
                }
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) ans+=c[i];
        }
        return ans;
        
    }
};
