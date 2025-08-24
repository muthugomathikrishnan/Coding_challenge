// Link : https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int l=0,mid=0,h=n-1;
    while(mid<=h){
        if(arr[mid]==0){
            swap(arr[mid],arr[l]);
            mid++;
            l++;
        }
        else if(arr[mid]==1) mid++;
        else if (arr[mid]==2) {
            swap(arr[h],arr[mid]);
            h--;
        }
    }
}
