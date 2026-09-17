class Solution {
public:
    int minSumOfLengths(vector<int>& v, int target) {
        int n=v.size();
        vector<int> minlen(n,INT_MAX);
        int l=0,ans=INT_MAX,currmin=INT_MAX;
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=v[i];
            while(sum>target){
                sum-=v[l++];
            }
            if(sum==target){
                int currlen=i-l+1;
                if(l>0 and minlen[l-1]!=INT_MAX){
                    ans=min(ans,minlen[l-1]+currlen);
                }
                currmin=min(currmin,currlen);
            }
            minlen[i]=currmin;
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};