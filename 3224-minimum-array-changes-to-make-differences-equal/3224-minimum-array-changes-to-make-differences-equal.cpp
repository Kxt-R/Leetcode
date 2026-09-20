class Solution {
public:
    int minChanges(vector<int>& v, int k) {
        int n=v.size();
        int p=n/2;
        vector<int> count(k+2);
        for(int i=0;i<p;++i){
            int mx=max(k-min(v[i],v[n-i-1]),max(v[i],v[n-i-1]));
            count[mx+1]++;
        }
        count[0]=p;
        for(int i=1;i<=k;++i){
            count[i]+=count[i-1];
        }
        for(int i=0;i<p;++i){
            int diff=abs(v[i]-v[n-i-1]);
            count[diff]--;
        }
        int ans=1e9;
        for(int i=0;i<=k;++i){
            ans=min(ans,count[i]);
        }
        return ans;
    }
};