// Link : https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]) return 0;
        }
        return 1;
    }
};
