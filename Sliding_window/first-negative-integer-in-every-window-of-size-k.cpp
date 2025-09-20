
// Link :https://www.naukri.com/code360/problems/first-negative-integer-in-every-window-of-size-k_1164406?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
    vector<int>ans;
    deque<int>dq;
    for(int i=0;i<n;i++){
        if(arr[i]<0) dq.push_back(i);
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        if(i>=k-1){
            if(!dq.empty()) ans.push_back(arr[dq.front()]);
            else ans.push_back(0);
        }
    }
    return ans;

}

