class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for(auto ele:nums1){
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==ele){
                    int j=i;
                    int ans=-1;
                    while(j<nums2.size()){
                        if(nums2[j]>ele){
                            ans=nums2[j];
                            break;
                        }
                        j++;
                    }
                    a.push_back(ans);
                    break;
                }
            }
        }
        return a;
    }
};