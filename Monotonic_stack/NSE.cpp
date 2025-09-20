// Link : https://www.naukri.com/code360/problems/next-smaller-element_1112581
#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{   
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        int num=arr[i];
        while(!st.empty() && st.top()>=num) st.pop();
        ans[i]=!st.empty() ? st.top() : -1;
        st.push(arr[i]);
    }
    return ans;
}
