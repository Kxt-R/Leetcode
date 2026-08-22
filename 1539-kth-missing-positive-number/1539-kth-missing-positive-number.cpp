class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int high=2002,low=1;
        while(high>low){
            int mid=(high+low+1)/2;
            auto it=lower_bound(arr.begin(),arr.end(),mid)-arr.begin();
            if(mid-it<=k){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};