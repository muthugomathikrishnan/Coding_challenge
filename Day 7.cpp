// Find the unique char in a stirng : https://leetcode.com/problems/first-unique-character-in-a-string/
// Solution 1: 
class Solution {
public:
    int firstUniqChar(string s) {
       int freq[26]={0};
       for(char c:s) freq[c-'a']++;

       for(int i=0;i<s.size();i++){ if(freq[s[i]-'a']==1) return i;}
       return -1; 
    }
};

// TC -> O(n)
// SC -> (1)

// Solution 2: brute force

class Solution {
public:
    int firstUniqChar(string s) {
       int n=s.size();

       for(int i=0;i<n;i++){
        bool find=false;
        for(int j=0;j<n;j++){
            if(i!=j && s[i]==s[j]){
                find=true;
                break;
            }
        }
        if(!find)return i;
       }
       return -1; 
    }
};



// TC -> O(N^2)
// SC -> O(1)




// Solution 3: "Hash Map Frequency Count"

class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,int>mp;
       for(char c: s) mp[c]++;
       for(int i=0;i<s.size();i++) {if(mp[s[i]]==1) return i; }
       return -1; 
    }
};

// TC -> O(N)
// SC -> O(1) // If the input is restricted to lowercase/uppercase alphabets → SC = O(1)

