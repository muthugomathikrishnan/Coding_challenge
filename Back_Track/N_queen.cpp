// link : https://leetcode.com/problems/n-queens/
class Solution {
private:
    bool isSafe(int r,int c,vector<string>&board,int n){
        int dr=r,dc=c;
        while(dr>=0 &&dc>=0){
            if(board[dr][dc]=='Q') return 0;
            dr--;
            dc--;
        }

        dr=r;
        dc=c;
        while(dr<n && dc>=0){
            if(board[dr][dc]=='Q') return 0;
            dr++;
            dc--;
        }
        dc=c;
        dr=r;
        while(dc>=0){
            if(board[dr][dc]=='Q') return 0;
            dc--;
        }
        return 1;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n) {
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        solve(0,board,ans,n);
        return ans;
    }
};
