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
