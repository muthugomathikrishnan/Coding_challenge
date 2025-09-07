// Link : https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     vector<int>ans;
     for(int n: nums1){
        int pos=-1;
        for(int i=0;i<nums2.size();i++)
            if(nums2[i]==n) {pos=i; break;}
        int greater=-1;
        for(int i=pos+1;i<nums2.size();i++)
            if(n<nums2[i]) {greater=nums2[i]; break;} 
        ans.push_back(greater);
     }
     return ans;   
    }
};
