// Single Number :https://leetcode.com/problems/single-number/
// Solution 1: using sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i+=2){
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[n-1];
    }
};

// TC -> O(N logN)
// SC -> O(1)


// Solution 2: using hash map



