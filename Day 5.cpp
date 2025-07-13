// Rotate Array 
// Link : https://leetcode.com/problems/rotate-array/

// Solution 1: Reverse Method 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

// TC -> O(N)+ O(k) + O(n-k) => O(N)
// SC -> O(1)

