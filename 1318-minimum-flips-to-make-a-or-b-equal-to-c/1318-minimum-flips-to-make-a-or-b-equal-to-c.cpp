class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<32;i++){
            int x=(a>>i) & 1;
            int y=(b>>i) & 1;
            int r=(c>>i) & 1;
            if(r==0){
                count+=x+y;
            }
            else{
                if(!(x+y)) count++;
            }
        }
        return count;
    }
};