class Solution {
public:
    int minCost(string colors, vector<int>& v) {
        int sum,cost=0,mx;
        int n=colors.size();
        for(int i=1;i<n;++i){
            sum=v[i-1],mx=v[i-1];
            while(i<n and colors[i]==colors[i-1]){
                sum+=v[i];
                mx=max(mx,v[i]);
                i++;
            }
            if(sum!=v[i-1]){
                cost+=sum-mx;
            }
        }
        return cost;
    }
};