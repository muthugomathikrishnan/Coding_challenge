// Link :https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        int maxi=0,mini=prices[0];
        for(int i=1;i<n;i++){
            int curr_p=prices[i]-mini;
            maxi=max(maxi,curr_p);
            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};
