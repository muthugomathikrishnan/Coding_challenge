// Single Number :https://leetcode.com/problems/single-number/
// Solution 1: using sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i+=2){
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[n-1];
    }
};

// TC -> O(N logN)
// SC -> O(1)


// Solution 2: using hash map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        unordered_map<int,int>mp;
        for(int i: nums) mp[i]++;
        for(auto it : mp){ if(it.second==1) return it.first;}
        return -1;
    }
};

// TC -> O(N)
// SC -> O(N)


// Solution 3 : XOR
// a^a=0
// 0^b=b
// (a^b)^c=a^(b^c)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int n: nums) result^=n;
        return result;
    }
};

// TC -> O(N)
// SC -> O(1)
