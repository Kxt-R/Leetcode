class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({aliceValues[i]+bobValues[i],i});
        }
        int ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans+=aliceValues[v[i].second];
            }
            else{
                ans-=bobValues[v[i].second];
            }
        }
        if(ans>0) return 1;
        else if(ans==0) return 0;
        else return -1;

    }
};