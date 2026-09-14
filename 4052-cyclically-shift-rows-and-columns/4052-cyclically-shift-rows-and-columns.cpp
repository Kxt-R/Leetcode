class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;++i){
            int x=rowShift[i]%n;
            rotate(grid[i].begin(),grid[i].begin()+x,grid[i].end());
        }
        for(int i=0;i<n;++i){
            int x=colShift[i]%n;
            vector<int> col(n);
            for(int j=0;j<n;++j) col[j]=grid[j][i];
            rotate(col.begin(),col.begin()+x,col.end());
            for(int j=0;j<n;++j) grid[j][i]=col[j];
        }
        return grid;
    }
};