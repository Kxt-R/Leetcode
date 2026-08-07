class Solution {
public:
    vector<int> dp=vector<int>(10005,-1);
    int helper(vector<int>& coins, int amount){
        if(amount ==0) return 0;
        if(amount<0) return 1e9;
        if(dp[amount]!=-1) return dp[amount];
        int mn=INT_MAX;
        for(int i=0;i<coins.size();i++){
            mn=min(mn,helper(coins,amount-coins[i]));
        }
        return dp[amount]=mn+1;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=helper(coins,amount);
        if(ans>=1e9) return -1;
        return ans;
    }
};