// Link :https://www.naukri.com/code360/problems/longest-consecutive-sequence_759408?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
bool search(vector<int>&arr ,int x){
    for(int n:arr)
        if(n==x) return 1;
    return 0;
}

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n==0) return 0;
    int l=1;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int cnt=1;

        while(search(arr,x+1)){
            cnt++;
            x++;
        }
        l=max(cnt,l);
    }
    return l;
}
