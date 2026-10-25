class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> move={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=1;i<n-1;++i){
            for(int j=1;j<m-1;++j){
                if(grid[i][j]==0){
                    bool valid=true;
                    q.push({i,j});
                    grid[i][j]=1;
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        int x=p.first;
                        int y=p.second;
                        for(auto mv:move){
                            int nx=x+mv[0];
                            int ny=y+mv[1];
                            if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==0){
                                grid[nx][ny]=1;
                                q.push({nx,ny});
                                if(nx==0 or nx==n-1 or ny==0 or ny==m-1) valid=0;
                            }
                        }
                    }
                    if(valid) ans++;
                }
            }
        }
        return ans;
    }
};