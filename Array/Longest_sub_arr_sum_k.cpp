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



// Sol 2:

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size();
    int r=0;
    long long p_sum=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        p_sum+=a[i];
        if(p_sum==k) r=max(r,i+1);
        long long rem=p_sum-k;
        if(mp.find(rem)!=mp.end())
            r=max(r,i-mp[rem]);
        else if(mp.find(p_sum)==mp.end())    
            mp[p_sum]=i;
    }
    return r;
}
