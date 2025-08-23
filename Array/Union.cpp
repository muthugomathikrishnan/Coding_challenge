// Link : https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int>st;
        for(int n:a) st.insert(n);
        for(int n:b) st.insert(n);
        vector<int>ans(st.begin(),st.end());
        return ans;
        
    }
};
