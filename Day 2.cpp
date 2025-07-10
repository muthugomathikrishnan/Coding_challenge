// Day 2: 
// Pascal's Triangle : https://leetcode.com/problems/pascals-triangle/

//solution:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return{{1}};
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
        
    }
};
