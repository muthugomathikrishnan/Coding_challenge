// Link : https://www.naukri.com/code360/problems/next-greater-element-i_3651446?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B) {
    unordered_map<int,int>mp;
    stack<int>st;
    for(int i=B.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=B[i]) st.pop();
        mp[B[i]]=st.empty() ? -1 : st.top();
        st.push(B[i]);
    }
    vector<int>ans;
    for(int i : A)
        ans.push_back(mp[i]);
    return ans;

}
