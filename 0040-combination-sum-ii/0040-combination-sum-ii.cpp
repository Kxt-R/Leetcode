class Solution {
public:
    vector<vector<int>> result;
    
    void play(vector<int> &cand,int idx, int target,vector<int> &subset){
        if(target==0){
            result.push_back(cand);
            return;
        }
        if(target<0) return;
        
        for(int i=idx;i<subset.size();i++){
            if(i>idx and subset[i]==subset[i-1]) continue;
            cand.push_back(subset[i]);
            play(cand,i+1,target-subset[i],subset);
            cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        play(subset,0,target,candidates);
        return result;
    }
};