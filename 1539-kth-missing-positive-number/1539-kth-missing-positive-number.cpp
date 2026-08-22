class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int high=n-1,low=0;
        if(arr[0]>k) return k;
        while(high>low){
            int mid=(high+low+1)/2;
            if(arr[mid]-mid-1<k){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return k+low+1;
    }
};