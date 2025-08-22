// Link : https://www.geeksforgeeks.org/problems/insertion-sort/1
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


// TC -> O(n ^2)
// SC -> O(1)
