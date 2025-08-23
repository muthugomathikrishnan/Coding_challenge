// Link :https://www.naukri.com/code360/problems/sorted-array_6613259?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
vector <int> sortedArray(vector < int > a, vector < int > b) {
    set<int>st;
    for(int n : a) st.insert(n);
    for(int n:b) st.insert(n);
    vector<int>ans(st.begin(),st.end());
    return ans;

}
