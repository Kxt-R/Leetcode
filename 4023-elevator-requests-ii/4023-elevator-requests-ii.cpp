class Solution {
public:
    int n;
    long long dp[1505][1505][2];
    long long run(int i,int j,int pos,vector<int>& v){
        if(i==0 and j==n-1) return 0;

        if(dp[i][j][pos]!=-1) return dp[i][j][pos];

        int curr=(pos==0) ? v[i] : v[j];
        int rem=n+i-j-1;
        long long min_pen=1e18;

        if(i>0) {
            long long x=(1LL)*rem*(curr-v[i-1])+ run(i-1,j,0,v);
            min_pen=min(min_pen,x);
        }
        if(j<n-1){
            long long y= (1LL)*rem*(v[j+1]-curr)+ run(i,j+1,1,v);
            min_pen=min(min_pen,y);
        }

        return dp[i][j][pos]=min_pen;
    }
    long long elevatorRequests(int r, int start, vector<int>& requests) {
        requests.push_back(start);
        n=requests.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        sort(requests.begin(),requests.end());
        auto it=lower_bound(requests.begin(),requests.end(),start);
        int i=(it-requests.begin());
        int j=i;
        return run(i,j,0,requests); 
    }
};