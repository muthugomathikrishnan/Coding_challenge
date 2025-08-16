// Link :https://leetcode.com/problems/sum-of-beauty-of-all-substrings/


class Solution {
public:
    int beautySum(string s) {
        int tot=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi=0,mini=INT_MAX;
                for(int f:freq){
                    if(f>0){
                        maxi=max(maxi,f);
                        mini=min(mini,f);
                    }
                }
                tot+=(maxi-mini);
            }
        }
        return tot;
    }
};
