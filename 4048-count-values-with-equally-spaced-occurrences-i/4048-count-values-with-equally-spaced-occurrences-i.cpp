class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        vector<vector<int>> pos(101);
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]].push_back(i);
            m[nums[i]]++;
        }
        for(auto x:m){
            if(x.second==3){
                int d=x.first;
                if(2*pos[d][1]==pos[d][0]+pos[d][2]) count++;
            }
        }
        return count;
    }
};