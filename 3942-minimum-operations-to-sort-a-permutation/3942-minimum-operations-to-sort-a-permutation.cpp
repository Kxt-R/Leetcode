class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool f1=true,f2=true;
        for(int i=1;i<n;i++){
            if((nums[i-1]+1)%n!=nums[i]) f1=false;
        }
        for(int i=1;i<n;++i){
            if((nums[i-1]-1+n)%n!=nums[i]) f2=false;
        }
        if(!f1 and !f2) return -1;
        if(f1 and f2) {
            if(nums[0]==0) return 0;
            else return 1;
        }
        int idx0;
        for(int i=0;i<n;++i) if(nums[i]==0) idx0=i;
        if(f2){
            if(idx0>=n/2) {
                idx0=(n-idx0-1);
                return idx0+1;
            }
            return idx0+2;
        }
        else{
            int ans=idx0;
            idx0=(n-idx0-1);
            ans=min(ans,idx0+3);
            return ans;
        }
    }
};