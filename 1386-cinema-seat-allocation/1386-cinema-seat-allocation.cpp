class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int k=reservedSeats.size();
        long long noseat=0;
        sort(reservedSeats.begin(),reservedSeats.end());
        int i=0;
        while(i<k){
            int j=reservedSeats[i][0];
            bool a=false,b=false,c=false;
            while(i<k and j==reservedSeats[i][0]){
                int pos=reservedSeats[i][1];
                if(!a and (pos>=2 and pos<=5)){
                    noseat++;
                    a=true;
                }
                if(!b and (pos>=4 and pos<=7)){
                    b=true;
                }
                if(!c and (pos>=6 and pos<=9)){
                    noseat++;
                    c=true;
                }
                i++;
            }
            if(a and c and !b){
                noseat--;
            }
        }
        return ((1LL)*n*2) -noseat;
    }
};