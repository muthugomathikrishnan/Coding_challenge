// Link : https://leetcode.com/problems/rotate-array/description/
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+n-1);
    reverse(arr.begin()+n-1,arr.end());

    return arr;
}


// without reverse:
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) { 
    n-=1;
    int s=arr.size(); 
    n%=s; 
    vector<int>temp(s,0); 
    for(int i=0;i<n;i++) temp[i]=arr[s-n+i]; 
    for(int i=0;i<s-n;i++) temp[n+i]=arr[i];
    return temp; 
}
