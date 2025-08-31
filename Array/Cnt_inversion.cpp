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


// Sol 2:
class Solution {
  private:
    int merge(vector<int>&arr,int l,int r,int mid){
        int cnt=0;
        int n1=mid-l+1,n2=r-mid;
        vector<int>L1(n1),L2(n2);
        for(int i=0;i<n1;i++) L1[i]=arr[l+i];
        for(int i=0;i<n2;i++) L2[i]=arr[mid+1+i];
        
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(L1[i]<=L2[j]) arr[k++]=L1[i++];
            else {
                cnt+=(n1-i);
                arr[k++]=L2[j++];
            }
        }
        
        while(i<n1) arr[k++]=L1[i++];
        while(j<n2) arr[k++]=L2[j++];
        
        return cnt;
    }
  
    
    int M_S(vector<int>&arr,int l, int r){
        int cnt=0;
        if(l>=r) return cnt;
        int mid=l+(r-l)/2;
        cnt+=M_S(arr,l,mid);
        cnt+=M_S(arr,mid+1,r);
        cnt+=merge(arr,l,r,mid);
    return cnt;
    }
  public:
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return M_S(arr,0,n-1);
    }
};
