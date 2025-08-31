// Link :https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}
