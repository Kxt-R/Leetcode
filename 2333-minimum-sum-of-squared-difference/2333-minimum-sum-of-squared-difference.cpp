class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=abs(nums2[i]-nums1[i]);
        }
        priority_queue<int> pq;
        for(int i=0;i<n;++i){
            pq.push(diff[i]);
        }
        long long count=1,top=pq.top();
        pq.pop();
        int k=k1+k2;
        while(!pq.empty()){
            int x=pq.top();
            if(count*(top-x)<=k){
                k-=count*(top-x);
                count++;
                top=x;
            }
            else{
                int div=k/count;
                top-=div;
                int rem=k%count;
                long long ans= ((1LL)*(count-rem)*top*top) + ((1LL)*rem*(top-1)*(top-1));
                while(!pq.empty()){
                    ans+=(1LL)*pq.top()*pq.top();
                    pq.pop();
                }
                return ans;
            }
            pq.pop();
        }
        int div=k/count;
        top-=div;
        if(top<=0) return 0;
        int rem=k%count;
        long long ans= ((1LL)*(count-rem)*top*top) + ((1LL)*rem*(top-1)*(top-1));
        return ans;
    }
};