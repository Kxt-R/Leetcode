class Solution {
public:
    int minCost(string colors, vector<int>& v) {
        int sum,cost=0;
        int n=colors.size();
        for(int i=1;i<n;++i){
            bool flag=0;
            int sum=v[i-1],mx=v[i-1];
            while(i<n and colors[i]==colors[i-1]){
                flag=1;
                sum+=v[i];
                mx=max(mx,v[i]);
                i++;
            }
            if(flag){
                cost+=sum-mx;
            }
        }
        return cost;
    }
};