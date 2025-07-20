// Link :https://leetcode.com/problems/power-of-three/
// Solution 1:
// if a number B is some power of A then, log B to the base A will always give an integer.
// Log base(A)B  = Log base 10 B/ Log base 10 A

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double L=log10(n)/log10(3);
        if(L-(int)L==0) return true;
        return false;
    }
};

// TC -> O(1)
// SC -> O(1)


// Sol 2: recursion 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%3==0) return isPowerOfThree(n/3);
        return false;
    }
};


// Sol 3: Iterative 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n%3==0) n/=3;
        if(n==1) return true;
        return false;
    }
};

