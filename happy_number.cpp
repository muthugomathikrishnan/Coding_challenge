// Link :https://leetcode.com/problems/happy-number/
class Solution {
    int square(int n){
        int num=0;
        while(n){
            int digit=n%10;
            num+=digit*digit;
            n/=10;
        }
        return num;
    }
public:
    bool isHappy(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_set<int>st;
        while(1){
            n=square(n);
            if(n==1) return 1;
            if(st.find(n)!=st.end()) return 0;
            st.insert(n);
        }
        return 1;
    }
};


// TC -> (Log N)
// SC -> O(N)



// Sol 2: 2 pointers

class Solution {
    int square(int n){
        int num=0;
        while(n){
            num+=(n%10)*(n%10);
            n/=10;
        }
        return num;
    }
public:
    bool isHappy(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int slow=n,fast=n;
        do{
            slow=square(slow);
            fast=square(square(fast));
        }
        while(slow!=fast);
        return (slow==1);
    }
};

// TC -> O(log N)
// SC -> O(1)
