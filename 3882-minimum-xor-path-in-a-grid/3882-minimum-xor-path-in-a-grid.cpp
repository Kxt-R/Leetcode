class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bitset<1024>>> dp(n,vector<bitset<1024>>(m));
        int xorr=grid[0][0];
        for(int i=1;i<m;++i){
            xorr^=grid[0][i];
            dp[0][i][xorr]=1;
        }
        xorr=grid[0][0];
        for(int i=1;i<n;++i){
            xorr^=grid[i][0];
            dp[i][0][xorr]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;j++){
                bitset<1024> left=dp[i][j-1];
                bitset<1024> up=dp[i-1][j];
                bitset<1024> final=left|up;

                for(int k=0;k<1024;++k){
                    if(final[k]==1) dp[i][j][k^grid[i][j]]=1;
                }
            }
        }
        for(int i=0;i<1024;++i){
            if(dp[n-1][m-1][i]==1) return i;
        }
        return grid[0][0];
    }  
    
};