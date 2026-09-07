class Solution {
public:
    int ask[26];
    const static int mod=1e9+7;
    int solve(int n,string &s){
        if(n==0) return 1;
        int prev=solve(n-1,s);
        int minus=ask[s[n-1]-'a']%mod;
        ask[s[n-1]-'a']=prev;
        int k=0;
        if(n==s.size()) k=1;
        return(((2LL*prev)%mod)-minus+mod-k)%mod;
    }
    int distinctSubseqII(string s) {
        for(int i=0;i<26;i++) ask[i]=0;
        int n=s.size();
        return solve(n,s);
    }
};