class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            int count=i;
            string t=s;
            rotate(t.begin(),t.begin()+i,t.end());
            int l=0,r=n-1;
            int temp;
            while(l<r){
                temp=abs(t[r]-t[l]);
                count+=min(temp,26-temp);
                r--;
                l++;
            }
            ans=min(count,ans);
        }
        return ans;
    }
};