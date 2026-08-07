class Solution {
public:
    int dp[303][5002];
    int run(int idx,int amount,vector<int> &v){
        if(amount==0) return 1;
        if(amount<0 or idx>=v.size()){
            return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        return dp[idx][amount]=(run(idx,amount-v[idx],v) + run(idx+1,amount,v));

    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return run(0,amount,coins);
    }
};