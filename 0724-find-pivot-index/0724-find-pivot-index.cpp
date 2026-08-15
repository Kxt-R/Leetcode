class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sumr=accumulate(nums.begin(),nums.end(),0);
        int suml=0;
        for(int i=0;i<n;i++){
            sumr-=nums[i];
            if(sumr==suml){
                return i;
            }
            suml+=nums[i];
        }
        return -1;
    }
};