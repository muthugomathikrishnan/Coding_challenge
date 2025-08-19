// Link : https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
class Solution {
  private:
    int f(int max_sum, vector<int>arr){
        int part=1,sum_arr=0;
        for(int i=0;i<arr.size();i++){
            if(sum_arr+arr[i]<=max_sum) sum_arr+=arr[i];
            else {
                part++;
                sum_arr=arr[i];
            }
        }
        return part;
    }
  public:
    int splitArray(vector<int>& arr, int k) {
        int last=*max_element(arr.begin(),arr.end());
        int tot_sum=accumulate(arr.begin(),arr.end(),0);
         int low = last, high = tot_sum, ans = tot_sum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (f(mid, arr) <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
