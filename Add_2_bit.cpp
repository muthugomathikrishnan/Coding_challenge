// Link : https://leetcode.com/problems/sum-of-two-integers/submissions/1735747432/
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            unsigned c=a&b;
            a^=b;
            b=c<<1;
        }
        return a;
    }
};
