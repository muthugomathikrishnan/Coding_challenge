// link :https://leetcode.com/problems/largest-odd-number-in-string/
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size()-1;
        for(int i=n;i>=0;i--){
            if((num[i]-'0') %2==1) return num.substr(0,i+1);
        }
        return "";
    }
};
