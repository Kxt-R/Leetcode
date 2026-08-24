class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<set<int>> primefac(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            set<int> s;
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    while(x%j==0){
                        x/=j;
                    }
                    s.insert(j);
                }
            }
            if(x!=1) s.insert(x);
            primefac[i]=s;
        }
        int ans=0,count=0;
        int i=0,j=0;
        map<int,int> m;
        while(i<n and j<n){
            if(primefac[j].size()<=k){
                while(j<n){
                    for(auto ele:primefac[j]){
                        m[ele]++;
                    }
                    if(m.size()>k){
                        for(auto ele:primefac[j]){
                            m[ele]--;
                            if(m[ele]==0) m.erase(ele);
                        }
                        break;
                    } 
                    count++;j++;
                }
                ans=max(count,ans);
                while(i<n){
                    for(auto ele:primefac[i]){
                        m[ele]--;
                        if(m[ele]==0) m.erase(ele);
                    }
                    count--;i++;
                    if(m.size()<=k) break;
                }
            }
            else{
                j++;
                i=j;
                m.clear();
                count=0;
            }
        }
        return ans;
    }
};