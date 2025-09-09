// Link :https://www.naukri.com/code360/problems/next-greater-element-ii_6212757?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int>& a) {
    int n=a.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<2*n;i++){
        int num=a[i%n];
        while(!st.empty() && a[st.top()]<num){
            ans[st.top()]=num;
            st.pop();
        }
        if(i<n) st.push(i);
    }
    return ans;
}
