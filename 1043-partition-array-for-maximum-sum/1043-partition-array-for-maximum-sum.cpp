class Solution {
public:
    int dp[505];
    int run(int idx,int &k,vector<int> &v){
        if(idx>=v.size()) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int maxval=0;
        int maxsum=0;

        for(int i=1;i<=k && i+idx<=v.size();i++){
            maxval=max(maxval,v[idx+i-1]);

            maxsum=max(maxsum,i*maxval + run(idx+i,k,v));
        }
        return dp[idx]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof dp);
        return run(0,k,arr);
    }
}; 