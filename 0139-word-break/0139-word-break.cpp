class Solution {
public:
    int dp[305];
    bool run(int idx,string &s,set<string> &dict){
        if(idx==s.size()){
            return true;
        }

        if(dp[idx]!=-1) return dp[idx];

        for(int i=idx;i<s.size();i++){
            if(dict.find(s.substr(idx,i-idx+1))!=dict.end()){
                if(run(i+1,s,dict)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof (dp));
        set<string> dict;
        for(auto x:wordDict) dict.insert(x);
        return run(0,s,dict);
    }
};