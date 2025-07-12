// Max-subArray:
// Link :https://leetcode.com/problems/maximum-subarray/submissions/1695028394/

// Soluition 1: brute-force approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
     if(n==1) return nums[0];
     int maxi=-1e9;

     for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
     } 
     return maxi;    
    }
};
// RTE : for O(N^2)
// TC -> (N^2)
// SC -> O(1)


// Solution 2 : TC -> O(N^2) to O(N)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
     if(n==1) return nums[0];
     int maxi=-1e9;
     int sum=0;
     for(int i=0;i<n;i++){
        sum+=nums[i];
        maxi=max(maxi,sum);
     } 
     return maxi;    
    }
};

// TC -> O(N)
// SC - O(1)


// Soltion 3 :  Kadane's Algorithm 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
     int current_sum=nums[0];
     int max_sum=nums[0];

     for(int i=1;i<n;i++){
        current_sum=max(nums[i],current_sum+nums[i]);
        max_sum=max(max_sum,current_sum);
     } 
     return max_sum;    
    }
};


// TC -> O(N)
// SC -> O(1)


