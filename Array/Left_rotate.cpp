// Link : https://leetcode.com/problems/rotate-array/description/
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+n-1);
    reverse(arr.begin()+n-1,arr.end());

    return arr;
}
