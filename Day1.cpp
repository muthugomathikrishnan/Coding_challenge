// link : https://leetcode.com/problems/set-matrix-zeroes/

// Solution 1:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int n=matrix.size(),m=matrix[0].size();
      vector<vector<int>>visit=matrix;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!matrix[i][j]){
                for(int k=0;k<m;k++) visit[i][k]=0;
                for(int k=0;k<n;k++) visit[k][j]=0;
            }
        }
      }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) matrix[i][j]=visit[i][j];
        }
    }
};



// TC ->O(n * m * (n+m))
// SC -> O(n*m)




// Solution 2:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int n=matrix.size(),m=matrix[0].size();
      int col0=1;
      for(int i=0;i<n;i++){
        if(!matrix[i][0]) col0=0;
        for(int j=1;j<m;j++)
            if(!matrix[i][j]) matrix[i][0]=matrix[0][j]=0;
      }
    

      for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>0;j--)
            if(!matrix[i][0] || !matrix[0][j]) matrix[i][j]=0;
        if(col0==0) matrix[i][0]=0;
      }
    }
};
// TC -> O(N*M)
// SC -> O(1)




