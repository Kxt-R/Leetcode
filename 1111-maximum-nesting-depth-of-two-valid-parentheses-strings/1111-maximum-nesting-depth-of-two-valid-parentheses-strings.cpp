class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans(n);
        int count=1;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                count++;
                if(count%2==0)ans[i]=1;
                else ans[i]=0;
            }
            else{
                if(count%2==0)ans[i]=1;
                else ans[i]=0;
                count--;
            }
        }
    
        return ans;
    }
};