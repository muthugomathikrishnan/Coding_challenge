// Link : https://leetcode.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char c:tasks) freq[c-'A']++;
        int maxi=*max_element(freq.begin(),freq.end());
        int max_c=count(freq.begin(),freq.end(),maxi);
        int part1=(maxi-1)*(n+1)+max_c;
        return max(part1,(int)tasks.size());
    }
};
