class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=nums[0],mn;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h;
        for(int i=0;i<n;i++) h.push({nums[i],i});
        for(int i=0;i<n;i++){
            while(1){
                pair<int,int> p=h.top();
                if(p.second<i) h.pop();
                else break;
            }
            mx=max(mx,nums[i]);
            mn=h.top().first;
            if(mx-mn<=k) return i;
        }
        return -1;
    }
};