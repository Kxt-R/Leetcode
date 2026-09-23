class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0,k=n-1;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;--i){
            sum+=nums[i];
            if(sum==x) ans=n-i;
            if(sum>x) {
                break;
            }
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==x) ans=min(i+1,ans);
            if(sum>x) {
                k=i;
                break;
            }
        }
        cout<<k<<'\n';
        for(int i=n-1;i>=0;--i){
            sum+=nums[i];
            while(k>=0 and sum>x){
                sum-=nums[k--];
            }
            if(sum==x and i>k) ans=min(ans,n-i+k+1);
            if(sum>x) break;
        }
        cout<<"f"<<ans<<'\n';
        return (ans==INT_MAX) ? -1 : ans;
    }
};