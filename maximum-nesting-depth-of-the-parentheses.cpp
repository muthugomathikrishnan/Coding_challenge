// link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
class Solution {
public:
    int maxDepth(string s) {
        int count=0,mx_count=0;
        for(char c:s){
            if(c=='('){
                count++;
                if(count>mx_count) mx_count=count;
            }
            else if(c==')') count--;
        }
        return mx_count;
    }
};
