// Link : https://leetcode.com/problems/missing-number/
// Sol 1: Brute force 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i) flag=1;
            }
            if(!flag) return i;        
        }
        return 0;
    }
};


// TC ->O(N^2)
// SC -> O(1)


// Sol 2: uing b_search

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]!=0) return 0;
        int l=nums[0],h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==mid) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};

// TC -> O(N long N)
// SC -> O(1)

// Optimal Solution 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expect=n*(n+1)/2;
        int actual=accumulate(nums.begin(),nums.end(),0);
        return expect-actual;
    }
};

// TC -> O(N)
// SC -> O(1)
