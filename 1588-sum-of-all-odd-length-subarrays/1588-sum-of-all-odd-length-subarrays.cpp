class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int countl=0,countr=n;
        long long ans=0;
        for(int i=0;i<n;i++){
            countr--;
            int totalsubarr=(countl+1)*(countr+1);
            int oddsubarr=(totalsubarr+1)/2;
            ans+=(1LL)*oddsubarr*arr[i];
            countl++;
        }
        return ans;
    }
};