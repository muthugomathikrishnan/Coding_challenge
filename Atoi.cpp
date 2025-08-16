// Link : https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        if(n==0) return 0;
        int i=0;
        while(i,n && s[i]==' ') i++;
        int sign=1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='-') ? -1:1;
            i++;
        }
        int result=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if (result > (INT_MAX - digit) / 10) 
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            i++;
        }
        return sign*result;
    }
};
