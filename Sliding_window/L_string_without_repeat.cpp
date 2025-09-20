// Llink : https://www.naukri.com/code360/problems/longest-substring-without-repeating-characters_758894?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
int lengthOfLongestSubstring(string &s) {
    int l=0,maxi=0;
    unordered_set<char>st;
    for(int r=0;r<s.length();r++){
        while(st.count(s[r])){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        maxi=max(maxi,r-l+1);
    }
    return maxi;
}
