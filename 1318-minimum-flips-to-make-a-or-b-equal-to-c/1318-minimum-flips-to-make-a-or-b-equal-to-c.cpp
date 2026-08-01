class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<32;i++){
            int x=(a>>i) & 1;
            int y=(b>>i) & 1;
            int r=(c>>i) & 1;
            if(r==0){
                if(x==1) count++;
                if(y==1) count++;
            }
            else{
                if(x==0 and y==0) count++;
            }
        }
        return count;
    }
};