class Solution {
public:
    vector<vector<int>> ans;
    void run(vector<int> &cand,vector<int> &sub,int &n){
        if(cand.size()==n){
            ans.push_back(cand);
            return;
        }
        for(int i=0;i<sub.size();i++){
            if(i!=0 and sub[i]==sub[i-1]) continue;
            cand.push_back(sub[i]);
            sub.erase(sub.begin()+i);
            run(cand,sub,n);
            sub.insert(sub.begin()+i,cand.back());
            cand.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cand;
        int n=nums.size();
        run(cand,nums,n);
        return ans;
    }
};