// Link : https://leetcode.com/problems/search-insert-position/description/?difficulty=EASY

// Sol 1: unig B_search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int r=nums.size()-1,l=0;
     while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) r=mid-1;
        else l=mid+1;
     }
     return l;   
    }
};

// TC -> O(log N)
