class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int high=n-1,low=0;
        if(arr[0]>k) return k;
        while(high>low){
            int mid=(high+low+1)/2;
            cout<<low<<' '<<high<<' '<<mid<<'\n';
            if(arr[mid]-mid-1<k){
                cout<<'h'<<'\n';
                low=mid;
            }
            else{
                cout<<'j'<<'\n';
                high=mid-1;
            }
        }
        return k+low+1;
    }
};