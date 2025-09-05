// Link :  https://www.naukri.com/code360/problems/capacity-to-ship-packages-within-d-days_1229379?ieSlug=amazon-interview-experience-apr-2025-exp-0-2-years&ieCompany=amazon

bool possible(vector<int>&weights,int d, int capacity){
    int c_day=1;
    int c_sum=0;
    for(int w : weights){
        if(w+c_sum>capacity){
            c_day++;
            c_sum=0;
        }
        c_sum+=w;
    }
    return c_day<=d;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int l=*max_element(weights.begin(),weights.end());
    int h=accumulate(weights.begin(),weights.end(),0);
    int ans=h;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(possible(weights,d,mid)){
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
