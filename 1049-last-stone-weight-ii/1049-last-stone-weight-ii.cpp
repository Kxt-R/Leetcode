class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<3005> bit;
        bit[0]=1;
        for(auto ele: stones){
            bit|=bit<<ele;
        }

        int total=accumulate(stones.begin(),stones.end(),0);
        int target=total/2;
        int i=target,j=target;
        while(1){
            if(i>=0 && bit[i]==1) return total-2*i;
            if(j<=total && bit[j]==1) return total-2*j;
            i--;
            j++;
        }
    }
};