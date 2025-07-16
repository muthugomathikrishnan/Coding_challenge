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


// Q2 : Related pbm :https://leetcode.com/problems/repeated-substring-pattern/

// Solution 1:
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int len=1;len<=n/2;len++){
            if( n % len !=0) continue;
            string r="";
            string sub=s.substr(0,len);
            for(int i=0;i<n/len;i++) r+=sub;
            if(r==s) return true;  
        }
        return false;
    }
};

// TC -> O(N^2)
// SC -> O(n)
