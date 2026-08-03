class Solution {
public:
    int n;
    int dp[50005];
    int run(int idx,vector<int> &v){
        if(idx>=n) return 0;

        if (dp[idx]!=-1) return dp[idx];

        int mx=INT_MIN;;
        if(idx+1<=n) mx=max(mx,v[idx]-run(idx+1,v));
        if(idx+2<=n) mx=max(mx,v[idx]+v[idx+1] -run(idx+2,v));
        if(idx+3<=n) mx=max(mx,v[idx]+v[idx+1]+v[idx+2]-run(idx+3,v));
        return dp[idx]=mx;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp,-1,sizeof dp);
        int temp=run(0,stoneValue);
        if(temp>0) return "Alice";
        else if(temp==0) return "Tie";
        else return "Bob";
    }
};