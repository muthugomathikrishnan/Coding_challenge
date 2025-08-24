// Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l=nums.size();
        
        vector<int>p(l/2,0),n(l/2,0);
        int i1=0,j1=0;
        for(int i: nums) {
            if(i>0) p[i1++]=i;
            else n[j1++]=i;
        }
        int i=0;
        while(i<l){
            nums[i++]=p.front();
            p.erase(p.begin());
            nums[i++]=n.front();
            n.erase(n.begin());
        }

        return nums;
    }
};
