// Link : https://leetcode.com/problems/reverse-pairs/submissions/1754528007/
class Solution {
private:
    int merge(vector<int>&nums,int l,int mid,int r){
        int j=mid+1;
        int cnt=0;
        for(int i=l;i<=mid;i++){
            while( j<=r && (long long )nums[i]> 2LL * nums[j]) j++;
            cnt+=j-(mid+1);
        }
        vector<int>temp;
        int i=l;
        j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=r) temp.push_back(nums[j++]);
        for(int k=l;k<=r;k++) nums[k]=temp[k-l];
        return cnt;        
    }


    int M_S(vector<int>&nums,int l,int r){
        int cnt=0;
        if(l>=r) return cnt;
        int mid=l+(r-l)/2;
        cnt+=M_S(nums,l,mid);
        cnt+=M_S(nums,mid+1,r);
        cnt+=merge(nums,l,mid,r);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return M_S(nums,0,n-1);
    }
};
