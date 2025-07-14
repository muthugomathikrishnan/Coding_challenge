//Reverse String : https://leetcode.com/problems/reverse-string/
// Solution 1: Using two pointers

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
};

// TC -> O(N)
// SC -> O(1)


// Solution 2: using stack
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(char c:s)st.push(c);
        s.clear();
        while(!st.empty()) {s.push_back(st.top()); st.pop();}
    }
};

// TC -> O(N)
// SC -> O(N)

// Solution 3: uisng inbuid reverse func

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

// TC -> O(N)
// SC -> O(1)
