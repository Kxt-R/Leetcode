class Solution {
public:
    int dp[502][502];
    int run(int i,int j,string &s1,string &s2){
        if(i>=s1.size() or j>=s2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int x=-1,y=-1;
        if(s1[i]==s2[j]) x=1+run(i+1,j+1,s1,s2);
        else{
            x=run(i+1,j,s1,s2);
            y=run(i,j+1,s1,s2);
        }
        return dp[i][j]=max(x,y);
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        int c=run(0,0,word1,word2);
        return word1.size()+word2.size()-2*c;
    }
};