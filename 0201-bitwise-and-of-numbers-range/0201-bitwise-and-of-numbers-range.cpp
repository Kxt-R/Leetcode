class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0) return 0;
        int msb2=31-__builtin_clz(right);
        int ans=0;
        while(msb2>=0){
            if(((right>>msb2)&1)==1 and ((left>>msb2)&1)==1) ans+=1<<msb2;
            else if(((right>>msb2)&1)==0 and ((left>>msb2)&1)==0) {

            }
            else break;
            msb2--;
        }
        return ans;
    }
};