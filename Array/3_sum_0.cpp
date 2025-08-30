// Link :https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==0) return 1;
                }
            }
        }
    return 0;
    }
};


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n) {
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	for(int i=0;i<n-2;i++){
		if(i>0 && arr[i]==arr[i-1]) continue;
		int l=i+1,r=n-1;
		while(l<r){
			if(arr[i]+arr[l]+arr[r]==0){
				ans.push_back(arr[i],arr[l],arr[k]);
				l++;
				r--;
				ans.push_back(temp);
			}
			else if(arr[i]+arr[l]+arr[r]<0) l++;
			else r--;
		}
	}
	return ans;
}
