class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        
        int i=1;
        while(true){
            while(nums[i]==i) i++;
            if(nums[i]==nums[nums[i]]) return nums[i];
            swap(nums[i],nums[nums[i]]);
            
        }
        return 0;
    }
};