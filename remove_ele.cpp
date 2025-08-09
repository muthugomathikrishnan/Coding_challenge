// Link :https://leetcode.com/problems/remove-element/

// Sol 1:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0,j=0;
        while(i<n){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};
