class Solution {
public:
    vector<vector<int>> dp=vector<vector<int>>(505,vector<int>(505,-1));
    int diff(vector<int>& v,int i,int j){
        if(i==j) return v[i];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = max (v[i]-diff(v,i+1,j),v[j]-diff(v,i,j-1));
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        int a=diff(piles , 0 , n-1);
        if(a>=0) return true;
        else return false;
    }
};