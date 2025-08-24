// Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l = nums.size();
        
        vector<int> p, n;
        for (int i : nums) {
            if (i > 0) p.push_back(i);
            else n.push_back(i);
        }

        int i1 = 0, j1 = 0;
        for (int i = 0; i < l; i++) {
            if (i % 2 == 0) nums[i] = p[i1++];  
            else nums[i] = n[j1++];            
        }

        return nums;
    }
};
