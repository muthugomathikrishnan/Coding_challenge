// link :https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return 1;
        int n=s.length();
        for(int i=0;i<n;i++){
            s+=s[0];
            s.erase(0,1);
            if(s==goal) return 1;
        }
        return 0;
    } 
};
