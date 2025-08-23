// Link : https://www.naukri.com/code360/problems/leaders-in-an-array_873144?leftPanelTabValue=SUBMISSION


#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &elements, int n) {
    vector<int>ans;
    int max_i=elements[n-1];
    ans.push_back(elements[n-1]);
    for(int i=n-2;i>=0;i--){
        if(elements[i]>max_i){
            ans.push_back(elements[i]);
            max_i=elements[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
