// Link :
// Brute_force:
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        for(int i=0;i<n;i++){
            int left_m=0,right_m=0;
            for(int j=0;j<=i;j++) left_m=max(left_m,height[j]);
            for(int j=i;j<n;j++) right_m=max(right_m,height[j]);
            water+=min(left_m,right_m)-height[i];
        }
        return water;
    }
};


// 
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        vector<int>left_m(n),right_m(n);
        left_m[0]=height[0];
        for(int i=1;i<n;i++) left_m[i]=max(left_m[i-1],height[i]);
        right_m[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) right_m[i]=max(right_m[i+1],height[i]);
        
        for(int i=0;i<n;i++) water+=min(right_m[i],left_m[i])-height[i];
        return water;
    }
};
