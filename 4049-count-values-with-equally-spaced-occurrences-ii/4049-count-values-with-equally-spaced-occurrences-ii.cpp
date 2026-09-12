class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,pair<bool,pair<int,int>>> m;
        map<int,int> o;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            o[x]++;
            if(o[x]==1){
                m[x]={false,{-1,i}};
            }
            else if(o[x]==2){
                int prev=m[x].second.second;
                m[x]={false,{i-prev,i}};
            }
            else if(o[x]==3){
                int prev=m[x].second.second;
                int diff=m[x].second.first;
                if(diff!=i-prev){
                    m[x]={false,{i-prev,i}};
                    continue;
                }
                m[x]={true,{i-prev,i}};
            }
            else if(m[x].first==true){
                int prev=m[x].second.second;
                int diff=m[x].second.first;
                if(diff!=i-prev){
                    m[x]={false,{i-prev,i}};
                    continue;
                }
                m[x]={true,{i-prev,i}};
            }
        }
        int count=0;
        for(auto p:m){
            //cout<<p.first<<' ';
            if(p.second.first==true) count++;
        }
        return count;
    }
};