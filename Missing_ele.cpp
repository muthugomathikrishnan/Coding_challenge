// Link : https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&category=Arrays,CPP&company=Amazon&sortBy=submissions
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n=arr.size();
        if(n==1 && arr[0]==1) return 2;
        unordered_set<int>st;
        for(int n: arr) st.insert(n);
        for(int i=1;i<=n+1;i++) {
            if(st.find(i)==st.end()) return i;
        }
        return -1;
        
    }
};


// Sol 2:
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size();
        long long expected = 1LL * (n + 1) * (n + 2) / 2;  // force 64-bit
        long long actual = 0;
        for (int x : arr) actual += x;                      // no shadowing
        return (int)(expected - actual);
    }
};
