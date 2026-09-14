class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int n=img1.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int count=0;
                int x=j;
                int y=i;
                for(int k=0;k+y<n;++k){
                    for(int l=0;l+x<n;++l){
                        if(img1[k][l]==1 and img2[k+y][l+x]==1) count++;
                    }
                }
                ans=max(count,ans);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int count=0;
                int x=j;
                int y=i;
                for(int k=0;k+y<n;++k){
                    for(int l=0;l+x<n;++l){
                        if(img1[k][l+x]==1 and img2[k+y][l]==1) count++;
                    }
                }
                ans=max(count,ans);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int count=0;
                int x=j;
                int y=i;
                for(int k=0;k+y<n;++k){
                    for(int l=0;l+x<n;++l){
                        if(img1[k+y][l]==1 and img2[k][l+x]==1) count++;
                    }
                }
                ans=max(count,ans);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int count=0;
                int x=j;
                int y=i;
                for(int k=0;k+y<n;++k){
                    for(int l=0;l+x<n;++l){
                        if(img2[k][l]==1 and img1[k+y][l+x]==1) count++;
                    }
                }
                ans=max(count,ans);
            }
        }
        return ans;
    }
};