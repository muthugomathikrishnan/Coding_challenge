// LinK : https://leetcode.com/problems/remove-outermost-parentheses/
// Sol 1:
class Solution {
public:
    string removeOuterParentheses(string s) {  
        string ans="";
        int count=0;
        for(char c:s){
            if(c=='('){
                if(count>0) ans+=c;
                count++;
            }
            else if(c==')'){
                count--;
                if(count>0) ans+=c;
            }
        }
        return ans;
    }
};
