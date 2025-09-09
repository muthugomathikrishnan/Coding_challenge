// Link : https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            int greater=-1;
            while(j%n!=i){
                if(nums[i]<nums[j%n]){
                    greater=nums[j%n];
                    break;
                }
                j++;
            }
            ans.push_back(greater);
        }
        return ans;
    }
};
