// Link :https://leetcode.com/problems/matrix-diagonal-sum/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=mat[i][i];
        int j=0;
        for(int i=n-1;i>=0;i--){ sum+=mat[j][i];j++;}
        if(n%2!=0) sum-=mat[n/2][n/2];
        return sum;
    }
};
