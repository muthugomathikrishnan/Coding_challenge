// Find the index of first occurrence :https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

//Solution 1:

class Solution {
public:
    int strStr(string h, string n) {
        int l1=h.size();
        int l2=n.size();
        if(l1<l2) return -1;
        for(int i=0;i<l1;i++){
            if(h[i]==n[0]){
            bool find=true;
            for(int j=0;j<l2;j++ ){
                if(h[i+j]!=n[j]){
                    find=false;
                    break;
                }
            }
            if(find) return i;
        }
        }
        return -1;
    }
};

// TC -> O(l1 * l2)
// SC -> O(1)
