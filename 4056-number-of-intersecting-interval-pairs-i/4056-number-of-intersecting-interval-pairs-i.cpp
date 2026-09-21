class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        for(int i=0;i<n;++i){
            int p1x1=intervals[i][0];
            int p1x2=intervals[i][1];
            for(int j=i+1;j<n;++j){
                int p2x1=intervals[j][0];
                int p2x2=intervals[j][1];
                if((p1x1<=p2x2 and p1x1>=p2x1) or (p1x2<=p2x2 and p1x2>=p2x1) or (p2x1<=p1x2 and p2x1>=p1x1) or (p2x2<=p1x2 and p2x2>=p1x1)) count++;
            }
        }
        return count;
    }
};