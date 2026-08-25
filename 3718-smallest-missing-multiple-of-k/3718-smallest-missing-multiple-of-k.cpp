class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int check=k;
        for(auto x:nums){
            if(x!=check){
                if(x>check) return check;
            }
            else check+=k;
        }
        return check;
    }
};