class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int n=fruits.size();
        int counta=1,countb=0;
        int a=fruits[0],b;
        int i=1;
        while(i<n && fruits[i]==a){
            counta++;
            i++;
        }
        if(i<n) {
            b=fruits[i];
            countb++;
        }
        ans=max(ans,counta+countb);
        for(int j=i+1;j<n;j++){
            if(fruits[j]!=a and fruits[j]!=b){
                if(fruits[j-1]==a){
                    countb=1;
                    counta=0;
                    for(int k=j-1;k>0;k--){
                        if(fruits[k]==a) counta++;
                        else break;
                    }
                    b=fruits[j];
                }
                else{
                    counta=1;
                    countb=0;
                    for(int k=j-1;k>0;k--){
                        if(fruits[k]==b) countb++;
                        else break;
                    }
                    a=fruits[j];
                }
            }
            else{
                if(fruits[j]==a){
                    counta++;
                    ans=max(ans,counta+countb);
                }
                else{
                    countb++;
                    ans=max(ans,counta+countb);
                }
            }
        }
        return ans;
    }
};