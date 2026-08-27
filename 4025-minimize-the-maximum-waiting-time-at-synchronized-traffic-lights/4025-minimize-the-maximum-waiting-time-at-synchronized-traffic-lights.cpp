class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=arrivalTime.size();
        for(int i=0;i<n;i++){
            arrivalTime[i]=arrivalTime[i]%period;
        }
        int mx=*max_element(lights.begin(),lights.end());
        int mnx=0;
        for(int i=0;i<n;i++){
            if(arrivalTime[i]>=mx){
                mnx=max(mnx,period-arrivalTime[i]);
            }
        }
        return mnx;
    }
};