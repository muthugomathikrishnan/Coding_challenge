// Link : https://leetcode.com/problems/reverse-pairs/submissions/1754376251/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if ((long long)nums[i] > 2LL * nums[j]) cnt++;
    return cnt;
    }
};
