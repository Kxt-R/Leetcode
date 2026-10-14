class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        vector<int> ans(n,-1);
        for(int i=0;i<n;++i){
            v[i]={i,nums[i]};
        }
        stack<pair<int,int>> st;
        for(auto x:v){
            while(!st.empty() and st.top().second<x.second){
                ans[st.top().first]=x.second;
                st.pop();
            }
            st.push(x);
        }
        for(auto x:v){
            while(!st.empty() and st.top().second<x.second){
                ans[st.top().first]=x.second;
                st.pop();
            }
        }
        return ans;
    }
};