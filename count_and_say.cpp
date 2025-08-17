// Link :https://leetcode.com/problems/count-and-say/

// Sol :
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string ans;
        for(int i=0;i<s.length();){
            int cnt=1;
            while(i<s.length() && s[i]==s[++i]) cnt++;
            ans+=to_string(cnt);
            ans+=s[i-1];
        }
        return ans;
    }
};
