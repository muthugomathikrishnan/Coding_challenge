// Link : https://www.naukri.com/code360/problems/4sum_5713771?leftPanelTabValue=SUBMISSION

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    if(n<4) return ans;
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i-1]==nums[i]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j-1]==nums[j]) continue;

            int l=j+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[j]+nums[l]+nums[r];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(sum<target) l++;
                else r--;
            }
        }
    }
    return ans;

}
