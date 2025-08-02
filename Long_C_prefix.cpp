// Link :

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string front=strs.front();
        string back=strs.back();
        int mini=min(front.length(),back.length());
        int i=0;
        while(i<mini && front[i]==back[i]) i++;
        return front.substr(0,i);
    }
};

// TC -> O(N Log N)
// SC -> O(1)
