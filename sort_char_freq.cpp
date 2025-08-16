// Link : https://leetcode.com/problems/sort-characters-by-frequency/submissions/1737101323/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c:s) freq[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto &p:freq) pq.push({p.second,p.first});

        string result="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            result.append(it.first,it.second);
        }

        return result;
    }
};
