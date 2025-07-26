// Link :https://leetcode.com/problems/valid-anagram/
// Sol 1: using sort

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s!=t) return false;
        return true;
    }
};

// TC -> O(N log N)
// SC -> O(N)


// Sol 2 : using hash map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mp;
        for(char c1:s) mp[c1]+=1;
        for(char c2:t) {if(mp.find(c2)!=mp.end()) mp[c2]-=1;}
        for(auto it:mp){ if(it.second!=0) return false;}
        return true;
    }
};
// TC -> O(N)
// SC -> O(N)


// Sol 3 : using freq count
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>freq(26,0);
        for(char c1 : s) freq[c1-'a']++;
        for(char c1 : t) freq[c1-'a']--;
        for(int c1:freq) {if(c1!=0) return false;}
        return true;
    }
};

// TC -> O(N)
// SC -> O(1)
