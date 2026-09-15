class Solution {
public:
    int dp[2005][2005];
    int solve(int i,int j,string &s,int &k){
        if(j>=s.size() or j-i+1<k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=i,y=j;
        bool flag=true;
        while(x<y){
            if(s[x++]!=s[y--]){
                flag=false;
                break;
            }
        }
        if(flag){
            return dp[i][j]=1+solve(j+1,j+k,s,k);
        }
        return dp[i][j]=max(solve(i+1,j,s,k),solve(i,j+1,s,k));
    }
    int maxPalindromes(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k-1,s,k);
    }
};