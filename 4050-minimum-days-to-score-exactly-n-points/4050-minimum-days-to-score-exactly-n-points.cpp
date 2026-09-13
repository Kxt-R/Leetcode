class Solution {
public:
    int dp[100005];
    int run(int n,vector<int> &streak){
        if(n==0){
            return -1;
        }

        if(dp[n]!=-1) return dp[n];

        int ans=INT_MAX;
        for(int i=1;i<1000;++i){
            if(n<streak[i]) break;
            ans=min(ans,i+1+run(n-streak[i],streak));
        }
        return dp[n]=ans;
    }
    int minDays(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int> streak(1000);
        int days=0;
        for(int i=1;i<1000;++i){
            streak[i]=(i*(i+1))/2;
        }
        return run(n,streak);
    }
};