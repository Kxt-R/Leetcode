class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> move={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]!=0){
                    long long sum=grid[i][j];
                    grid[i][j]=0;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        int x=p.first;
                        int y=p.second;
                        for(auto mv:move){
                            int nx=x+mv[0];
                            int ny=y+mv[1];
                            if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]!=0){
                                sum+=grid[nx][ny];
                                grid[nx][ny]=0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};