// Link : https://leetcode.com/problems/shortest-palindrome/

class Solution {
private:
    vector<int> C_LPS(string s){
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
                else{ lps[i]=0;i++;}
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(rev==s) return s;
        string com=s+"#"+rev;
        vector<int>lps=C_LPS(com);
        int l_prefix=lps.back();
        string suffix=s.substr(l_prefix);
        reverse(suffix.begin(),suffix.end());
        return suffix+s;
    }
};
