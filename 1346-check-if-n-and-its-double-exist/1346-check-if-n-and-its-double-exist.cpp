class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(auto ele:arr){
            if(s.find(ele*2)!=s.end()) return true;
            if(ele%2==0){
                if(s.find(ele/2)!=s.end())return true;
            }
            s.insert(ele);
        }
        return false;
    }
};