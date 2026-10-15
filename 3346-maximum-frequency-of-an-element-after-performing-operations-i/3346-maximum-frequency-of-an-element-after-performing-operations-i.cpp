class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int range=1e5+5;
        vector<vector<int>>diff(2,vector<int>(2*range,0));
        for(int i=0;i<n;++i){
            int up=nums[i]+k;
            int low=nums[i]-k;
            if(up>=0 and low<0 ){
                diff[1][up+1]--;
                diff[1][0]++;
                diff[0][0]--;
                diff[0][-low]++;
            }
            else if(low>=0){
                diff[1][up+1]--;
                diff[1][low]++;
            }
            else{
                diff[0][-(up+1)]--;
                diff[0][-low]++;
            }
        }
        for(int i=range;i>0;--i){
            diff[0][i]+=diff[0][i+1];
        }
        for(int i=1;i<2*range-1;++i){
            diff[1][i]+=diff[1][i-1];
        }
        map<int,int> m;
        for(int i=0;i<n;++i) m[nums[i]]++;
        int ans=-1;
        for(int i=1;i<range;++i){
            if(m.contains(-i))ans=max(ans,min(diff[0][i],m[-i]+numOperations));
            else ans=max(ans,min(diff[0][i],numOperations));
        }
        for(int i=0;i<2*range-1;++i){
            if(m.contains(i))ans=max(ans,min(diff[1][i],m[i]+numOperations));
            else ans=max(ans,min(diff[1][i],numOperations));
        }
        return ans;
    }
};