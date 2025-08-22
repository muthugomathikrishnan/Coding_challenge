// Link : https://leetcode.com/problems/longest-happy-prefix/
class Solution {
private:
    vector<int>C_LPS(string s){
        int n=s.length();
        int i=1,len=0;
        vector<int>lps(n,0);
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }

            else {
                if(len!=0) len=lps[len-1];
                else {
                    len=0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    string longestPrefix(string s) {
        vector<int>lps=C_LPS(s);
        int l_prefix=lps.back();
        return s.substr(0,l_prefix);
    }
};
