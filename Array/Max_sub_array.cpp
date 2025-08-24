// Link : https://www.naukri.com/code360/problems/maximum-subarray-sum_630526?leftPanelTabValue=SUBMISSION
long long maxSubarraySum(vector<int> arr, int n)
{
    long long curr_s=arr[0];
    long long  max_s=0;
    for(int i=1;i<n;i++){
        curr_s=max(curr_s+arr[i],(long long) arr[i]);
        max_s=max(max_s,curr_s);
    }
    return max_s;
}
