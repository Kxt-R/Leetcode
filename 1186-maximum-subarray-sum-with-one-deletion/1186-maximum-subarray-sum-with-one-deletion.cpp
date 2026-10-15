class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int sum=arr[0],sumskip=arr[0];
        int ans=arr[0];
        for(int i=1;i<arr.size();++i){
            if(sumskip<0){
                sumskip=0;
            }
            
            if(arr[i]>=0) sumskip+=arr[i];
            else{
                sumskip=max(sumskip+arr[i],sum);
            }

            if(sum<0) sum=0;
            sum+=arr[i];

            ans=max({ans,sum,sumskip});
        }
        return ans;
    }
};