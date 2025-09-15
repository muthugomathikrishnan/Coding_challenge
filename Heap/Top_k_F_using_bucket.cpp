// Link :https://www.naukri.com/code360/problems/k-most-frequent-elements_3167808?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>freq;
    for(int i : arr) freq[i]++;
    vector<vector<int>>bucket(n+1);
    for(auto&it:freq) bucket[it.second].push_back(it.first);
    vector<int>ans;
    for(int i=n;i>=0 && ans.size()<k;i--){
        for(int j:bucket[i]){
            ans.push_back(j);
            if(ans.size()==k) return ans;
        }
    }
    return ans;
}
