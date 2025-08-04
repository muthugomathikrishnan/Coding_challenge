// Link :

// Sol 1 : Using sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
// TC -> O(N log N)

