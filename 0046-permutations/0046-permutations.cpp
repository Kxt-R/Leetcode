class Solution {
public:
    void run(vector<int> &v,vector<int> &cand,vector<vector<int>> &ans){
        if(cand.size()==0) {
            ans.push_back(v);
            return;
        }

        for(int i=0;i<cand.size();i++){
            v.push_back(cand[i]);
            cand.erase(cand.begin()+i);
            run(v,cand,ans);
            cand.insert(cand.begin()+i,v.back());
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        run(v,nums,ans);
        return ans;
    }
};