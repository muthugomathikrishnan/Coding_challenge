// link :
https://leetcode.com/problems/repeated-string-match/submissions/1738105778/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a;
        int cnt=1;
        while(s.size()<b.size()){
            s+=a;
            cnt++;
        }
        if(s.find(b)!=string::npos) return cnt;
        s+=a;
        cnt++;
        if(s.find(b)!=string::npos) return cnt;
        return -1;
    }
};
