// Link :

// Sol 1 : brute force 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                char val=board[r][c];
                for(int i=0;i<9;i++){
                    if(board[r][i]==val && i!=c) return false;
                    if(board[i][c]==val && i!=r) return false;
                }

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        int new_r=3*(r/3)+i;
                        int new_c=3*(c/3)+j;
                        if(board[new_r][new_c]==val){
                            if(new_r!=r && new_c!=c) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


// TC -> 2187 → O(1) (constant time)
// SC -> O(1)
