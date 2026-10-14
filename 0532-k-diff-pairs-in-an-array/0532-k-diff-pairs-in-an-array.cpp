class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            int count=0;
            unordered_map<int,int> m;
            for(auto x:nums) m[x]++;
            for(auto p:m){
                if(p.second>=2) count++;
            }
            return count;
        }
        unordered_set<int> s;
        for(auto x:nums) s.insert(x);
        int count=0;
        for(auto x:s){
            if(s.contains(x+k)) count++;
            if(s.contains(x-k)) count++;
        }
        return count/2;
    }
};