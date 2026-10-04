class Solution {
public:
    int dp[102][102];
    bool run(int idx,int count,string &s){
        if(idx==s.size()){
            if(count==0) return true;
            else return false;
        }
        if(count<0) return false;
        if(dp[idx][count]!=-1) return dp[idx][count];
        bool temp;
        if(s[idx]=='(') temp=run(idx+1,count+1,s);
        else if(s[idx]==')') temp=run(idx+1,count-1,s);
        else if(s[idx]=='*'){
            temp=run(idx+1,count,s);
            temp|=run(idx+1,count+1,s);
            temp|=run(idx+1,count-1,s);
        }
        return dp[idx][count]=temp;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof (dp));
        return run(0,0,s);
    }
};