// Link : https://leetcode.com/problems/palindromic-substrings/
class Solution {
    bool isPal(string s, int i ,int j){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
public:
    int countSubstrings(string s) {
        int cnt=0,n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPal(s,i,j)) cnt++;
            }
        }
        return cnt+n;
    }
};
