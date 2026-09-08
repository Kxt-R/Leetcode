class Solution {
public:
    int countCommas(int n) {
        int total=n-999;
        return (total<0) ? 0 : total;
    }
};