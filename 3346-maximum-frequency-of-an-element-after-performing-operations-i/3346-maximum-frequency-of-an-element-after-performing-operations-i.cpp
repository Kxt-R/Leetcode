class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int range=1e5+5;
        vector<int>diff(2*range,0);
        for(int i=0;i<n;++i){
            int up=nums[i]+k;
            int low=nums[i]-k;
            if(up>=0 and low<0 ){
                diff[up+1]--;
                diff[0]++;
            }
            else{
                diff[up+1]--;
                diff[low]++;
            }
        }
        for(int i=1;i<2*range-1;++i){
            diff[i]+=diff[i-1];
        }
        vector<int> m(2*range,0);
        for(int i=0;i<n;++i) m[nums[i]]++;
        int ans=-1;
        for(int i=0;i<2*range-1;++i){
            ans=max(ans,min(diff[i],m[i]+numOperations));
        }
        return ans;
    }
};