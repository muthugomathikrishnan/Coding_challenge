// Sol 1:

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        unordered_set<int>row[n],col[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];
                if(row[i].count(val) || col[j].count(val)) return 0;
                row[i].insert(val);
                col[j].insert(val);
            }
        }
        return 1;
    }
};
