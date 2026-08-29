class Solution {
public:
    vector<vector<int>> result;
    
    void play(vector<int> &cand,int idx, int target,vector<int> &subset){
        if(target==0){
            result.push_back(cand);
            return;
        }
        
        for(int i=idx;i<subset.size();i++){
            if(target-subset[i]<0) break;
            cand.push_back(subset[i]);
            play(cand,i,target-subset[i],subset);
            cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        play(subset,0,target,candidates);
        return result;   
    }
    
};