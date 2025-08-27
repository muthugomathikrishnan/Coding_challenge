// Link : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=SUBMISSION

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size();
    int r=0;

    for(int i=0;i<n;i++){
        long long  p_sum=0;
        for(int j=i;j<n;j++){
            p_sum+=a[j];
            if(p_sum==k) r=max(r,j-i+1);
        }
    }
    return r;
}


