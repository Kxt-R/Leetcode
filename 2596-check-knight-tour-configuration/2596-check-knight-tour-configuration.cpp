class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> pos={{-1,2},{1,2},{-2,1},{2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};
        pair<int,int> currpos;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) currpos={j,i};
            }
        }
        int k=1;
        bool flag=true;
        while(k<(n*n)){
            int x=currpos.first;
            int y=currpos.second;
            bool newpos=false;
            for(int i=0;i<8;++i){
                int nx=x+pos[i][0];
                int ny=y+pos[i][1];
                if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==k){
                    currpos={nx,ny};
                    ++k;
                    newpos=true;
                    break;
                }
            }
            if(!newpos) break;
        }
        if(k==n*n) return true;
        return false;
    }
};