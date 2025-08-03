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


// Sol 2 : without sorthing 
// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        if(arr.empty()) return "";
        string prefix=arr[0];
        
        for(int i=1;i<arr.size();i++){
            int j=0;
            while(j<prefix.size() && j<arr[i].size() && prefix[j]==arr[i][j]) j++;
            prefix=prefix.substr(0,j);
            if(prefix.empty()) return "";
        }
        return prefix;
        
    }
};


// TC -> O(N)
// SC -> O(1)
