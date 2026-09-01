class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        string s="";
        int temp;
        for(int i=0;i<n;i++){
            if(s==""){
                temp=nums[i];
                s+=to_string(nums[i]);
                if(i==n-1){
                    ans.push_back(s);
                    break;
                }
                continue;
            }
            while(i<n and nums[i]==nums[i-1]+1){
                i++;
            }
            i--;
            if(temp!=nums[i]){
                s+="->";
                s+=to_string(nums[i]);
            }
            ans.push_back(s);
            s="";
        }
        return ans;
    }
};