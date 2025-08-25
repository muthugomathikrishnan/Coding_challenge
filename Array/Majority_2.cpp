// Link : https://leetcode.com/problems/majority-element-ii/submissions/1747298539/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i : nums) mp[i]++;
        int fr=n/3;
        vector<int>ans;
        for(auto &p : mp){
            if(p.second>fr) ans.push_back(p.first);
        }
        return ans;
    }
};
