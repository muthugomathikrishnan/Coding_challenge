// Link : https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category=Arrays,Strings,CPP&company=Amazon&sortBy=submissions
// Sol 1:
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        
        vector<int>ans(2,0);
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr+=arr[j];
                if(curr==target){
                    ans[0]=i+1;
                    ans[1]=j+1;
                    return ans;
                }
            }
        }
        return {-1};
        
    }
};
