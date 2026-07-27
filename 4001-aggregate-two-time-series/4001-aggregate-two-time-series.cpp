class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n=series1.size(),m=series2.size();
        int ptr1=0,ptr2=0;
        vector<vector<int>> ans;
        while(ptr1!=n && ptr2!=m){
            if(series1[ptr1][0]==series2[ptr2][0]){
                ans.push_back({series1[ptr1][0],series1[ptr1][1] + series2[ptr2][1]});
                if(ptr2<m) ptr2++;
                if(ptr1<n) ptr1++;
                continue;
            }
            if(series1[ptr1][0]<series2[ptr2][0]){
                ans.push_back({series1[ptr1][0],series1[ptr1][1] + series2[ptr2][1]});
                if(ptr1<n) ptr1++;
                continue;
            }
            if(series1[ptr1][0]>series2[ptr2][0]){
                ans.push_back({series2[ptr2][0],series1[ptr1][1] + series2[ptr2][1]});
                if(ptr2<m) ptr2++;
                continue;
            }
        }
        while(ptr1<n){
            ans.push_back({series1[ptr1][0],series1[ptr1][1]});
            ptr1++;
        }
        while(ptr2<m){
            ans.push_back({series2[ptr2][0],series2[ptr2][1]});
            ptr2++;
        }
        return ans;
    }
};