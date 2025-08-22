// Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string h, string n) {
        int l1=h.size();
        int l2=n.size();
        if(l1<l2) return -1;
        for(int i=0;i<l1;i++){
            if(h.substr(i,l2)==n) return i;
        }        
        return -1;
    }
};
