// link :https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        
        int max_1=arr[0],max_2=-1;
        for(int n:arr) max_1=max(max_1,n);
        
        for(int n: arr){
            if(n>max_2 && n!=max_1) max_2=n;
        }
        return max_2;
    }
};
