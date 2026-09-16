class Solution {
public:
    int dp[1005][1005][2];
    const int mod=1e9+7;
    int run(int idx,int k,int &n,int start){
        if(k==0) return 1;
        if(idx>=n) return 0;

        if(dp[idx][k][start]!=-1) return dp[idx][k][start];

        long long ans=0;
        if(start==0) {
            int skip=run(idx+1,k,n,0)%mod;
            int take=run(idx+1,k,n,1)%mod;
            ans=(skip+take)%mod;
        }
        else{
            int extend=run(idx+1,k,n,1)%mod;
            int end=run(idx,k-1,n,0)%mod;
            ans=(extend+end)%mod;
        }
        return dp[idx][k][start]=ans;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return run(0,k,n,0);
    }
};