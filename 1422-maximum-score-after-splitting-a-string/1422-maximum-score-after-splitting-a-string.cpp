class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int count1=0,count0=0;
        int ans=-1;
        for(int i=0;i<n;++i) if(s[i]=='1') count1++;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0') count0++;
            else count1--;
            ans=max(ans,count0 + count1);
        }
        return ans;
    }
};