// Link :https://leetcode.com/problems/number-of-1-bits/

// Sol 1:  Brian Kernighan’s Algorithm

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n){
            n&=(n-1);
            count ++;
        }
        return count;
    }
};

// TC -> O(number of set bits)


// Sol 2:
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)) count++;
        }
        return count;
    }
};


// Sol 3 : 
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);;
    }
};

