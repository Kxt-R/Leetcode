class Solution {
public:
    bool gooddiffarray(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n=nums.size();
        vector<int> diff(n+1);
        for(int i=0;i<k;++i){
            diff[queries[i][0]]-=queries[i][2];
            diff[queries[i][1]+1]+=queries[i][2];
        }
        for(int i=1;i<n;++i) diff[i]+=diff[i-1];
        for(int i=0;i<n;++i) {
            diff[i]+=nums[i];
            if(diff[i]>0) return false;
        }
        return true; 
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,h=queries.size();
        int ans=-1;
        while(l<=h){
            int mid=l + (h-l)/2;
            if(gooddiffarray(nums,queries,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};