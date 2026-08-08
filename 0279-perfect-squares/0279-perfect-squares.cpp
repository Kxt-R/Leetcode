class Solution {
public:
    int dp[105][10005];
    int run(int curr,int left){
        if(left==0) return 0;
        if(left<0|| curr>102) return 1e4+1;

        if(dp[curr][left]!=-1) return dp[curr][left];

        return dp[curr][left]=min(1+run(curr,left-(curr*curr)),run(curr+1,left));
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof dp);
        return run(1,n); 
    }
};