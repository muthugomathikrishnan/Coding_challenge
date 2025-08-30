// Link : https://leetcode.com/problems/find-missing-and-repeated-values/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int r=0,miss=0;
        int n=grid.size(),m=grid[0].size();
        int maxi=m*n;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!st.count(grid[i][j])) st.insert(grid[i][j]);
                else r=grid[i][j];
                maxi=max(grid[i][j],maxi);
            }
        }

        for(int i=1;i<=maxi;i++){
            if(!st.count(i)) miss=i;
        }
        return {r,miss};
    }
};
