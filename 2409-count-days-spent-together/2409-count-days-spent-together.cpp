class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(arriveAlice<arriveBob){
            if(arriveBob>leaveAlice) return 0;
            int aliceleav=stoi(leaveAlice.substr(3,2));
            int bobleav=stoi(leaveBob.substr(3,2));
            int bobarr=stoi(arriveBob.substr(3,2));

            for(int i=0;i<stoi(arriveBob.substr(0,2))-1;++i) bobarr+=month[i];
            for(int i=0;i<stoi(leaveAlice.substr(0,2))-1;++i) aliceleav+=month[i];
            for(int i=0;i<stoi(leaveBob.substr(0,2))-1;++i) bobleav+=month[i];
            return min(aliceleav,bobleav)-bobarr+1;
        }
        else{
            if(arriveAlice>leaveBob) return 0;
            int aliceleav=stoi(leaveAlice.substr(3,2));
            int bobleav=stoi(leaveBob.substr(3,2));
            int alicearr=stoi(arriveAlice.substr(3,2));

            for(int i=0;i<stoi(arriveAlice.substr(0,2))-1;++i) alicearr+=month[i];
            for(int i=0;i<stoi(leaveAlice.substr(0,2))-1;++i) aliceleav+=month[i];
            for(int i=0;i<stoi(leaveBob.substr(0,2))-1;++i) bobleav+=month[i];
            return min(aliceleav,bobleav)-alicearr+1;
        }
        return 0;
    }
};