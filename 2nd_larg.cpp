// Link :https://www.naukri.com/code360/problems/second-largest-element-in-the-array_873375
#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    int max_1=INT_MIN, max_2=INT_MIN;
    for(int n: arr){
        if(n>max_1){
            max_2=max_1;
            max_1=n;
        }
        else if(n>max_2 && n<max_1) max_2=n;
    }
    return (max_2==INT_MIN) ? -1 : max_2;
}
