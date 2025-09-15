// Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=problem-list-v2&envId=heap-priority-queue

// Brute force :
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return -1;
        if(n==2) return (nums[0]-1)*(nums[1]-1);
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,((nums[i]-1) * (nums[j]-1)));
            }
        }
        return maxi;
    }
};


// Optimal : 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return -1;
        sort(nums.begin(),nums.end());
        return (nums[n-2]-1) * (nums[n-1]-1);

    }
};
