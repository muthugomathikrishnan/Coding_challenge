// Link :https://leetcode.com/problems/max-consecutive-ones/submissions/1745255541/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,c=0;
        for(int n :nums){
            if(n==1){ c++; maxi=max(maxi,c);}
            else c=0;
        }
        return maxi; 
    }
};
