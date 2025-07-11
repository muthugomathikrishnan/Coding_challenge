// Find_Dublicate:
// Link :https://leetcode.com/problems/find-the-duplicate-number/

// Solution 1: Hash Set Approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int n: nums){
            if(st.find(n)!=st.end()) return n;
            st.insert(n); 
        }
        return -1;
    }
};

// TC : O(N) 
// SC : O(N)

// Solution 2: using sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==nums[i+1]) return nums[i];
        return -1;
    }
};

// TC -> O(N logN)
// SC -> O(1)


// Solution 3 : Floyd’s Tortoise and Hare Algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){ slow=nums[slow];fast=nums[fast];}
        return slow;
    }
};

// TC -> O(N)
// SC -> O(1)
