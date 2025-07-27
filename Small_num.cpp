// Link : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// Sol 1 : brute force 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(nums[j]<nums[i]) c++;
            }
            res[i]=c;
        }
        return res;
    }
};
// TC -> O(n ^2)
// SC -> O(n)


// Sol 2: using hash map
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        map<int,int>freq;
        for(int num : nums) freq[num]++;
        map<int,int>prefix;
        int sum=0;
        for(auto it : freq){
            prefix[it.first]=sum;
            sum+=it.second;
        }
        for(int i=0;i<n;i++) res[i]=prefix[nums[i]];
        return res;
        }
};

// TC -> O(n log n)
// SC -> O(n + k)
