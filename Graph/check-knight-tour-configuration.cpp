// Link : https://leetcode.com/problems/check-knight-tour-configuration/
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.size();
        vector<pair<int,int>>pos(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                pos[grid[i][j]]={i,j};
        }
        for(int i=0;i<n*n-1;i++){
            auto [r1,c1]=pos[i];
            auto [r2,c2]=pos[i+1];
            int dr=abs(r2-r1);
            int dc=abs(c2-c1);

            if(!((dc==2 && dr==1) || (dc==1 && dr==2))) return false;

        }

    return true;
    }
};
