// Link :https://leetcode.com/problems/search-a-2d-matrix/submissions/1648593080/
bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r=mat.size(),c=mat[0].size();
        int top=0,bot=r-1;
        while(top<=bot){
            int mid=top+(bot-top)/2;
            if(mat[mid][0]<target && mat[mid][c-1]>target) break;
            else if(mat[mid][0]>target) bot=mid-1;
            else top=mid+1;
        }
        int row=(top+bot)/2;
        int left=0,right=c-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mat[row][mid]==target) return 1;
            else if(mat[row][mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
}
