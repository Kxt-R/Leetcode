class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        vector<vector<int>> cornor={{x1,y1},{x2,y2},{x1,y2},{x2,y1}};
        for(int i=0;i<4;i++){
            long long d=(xCenter-cornor[i][0])*(xCenter-cornor[i][0]);
            d+=(yCenter-cornor[i][1])*(yCenter-cornor[i][1]);
            if(radius*radius>=d){
                return 1;
            }
        }

        if(xCenter>=x1-radius and xCenter<=x2+radius and yCenter>=y1 and yCenter<=y2) return 1;
        if(xCenter>=x1 and xCenter<=x2 and yCenter>=y1-radius and yCenter<=y2+radius) return 1;

        return 0;
    }
};