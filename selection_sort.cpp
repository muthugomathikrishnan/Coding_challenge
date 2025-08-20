class Solution {
  public:
  
  void selectionSort(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            int ch_ind=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[ch_ind]) ch_ind=j;
            }
            swap(arr[ch_ind],arr[i]);
        }
    }
};
