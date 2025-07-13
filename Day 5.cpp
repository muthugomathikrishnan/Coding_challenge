// Rotate Array 
// Link : https://leetcode.com/problems/rotate-array/

// Solution 1: Iteration method 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        for(int i=0;i<k;i++){
            int last=nums[n-1];
            for(int j=n-1;j>0;j--) nums[j]=nums[j-1];
            nums[0]=last;
        }
        
    }
};
// TC -> O(N * k)
// SC -> O(N)


// Solution 2: using temp array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int>temp(n,0);
        for(int i=0;i<k;i++) temp[i]=nums[n-k+i];
        for(int i=0;i<n-k;i++) temp[k+i]=nums[i];
        for(int i=0;i<n;i++) nums[i]=temp[i];
        
    }
};

// TC -> O(N)
// SC -> O(N)




// Solution 3: Reverse Method 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

// TC -> O(N)+ O(k) + O(n-k) => O(N)
// SC -> O(1)




