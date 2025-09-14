// Link :https://leetcode.com/problems/subsets/
class Solution {
    void backTrack(int start,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp){
        ans.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backTrack(i+1,nums,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        backTrack(0,nums,ans,temp);
        return ans;
    }
};
