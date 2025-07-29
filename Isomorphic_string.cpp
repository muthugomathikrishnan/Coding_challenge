// Link : https://leetcode.com/problems/isomorphic-strings/

// Sol 1 : using hash map

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();

        unordered_map<char,int>m1,m2;
        for(int i=0;i<n;i++){
            if(m1.find(s[i])==m1.end())
                m1[s[i]]=i;
            if(m2.find(t[i])==m2.end())
                m2[t[i]]=i;
            if(m1[s[i]]!=m2[t[i]]) return false;
        }
        return true;
    }
};

// TC -> O(N)
// SC -> O(1)
