class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int digits=num;
        int no9=sum/9;
        int rem=sum%9;
        if((sum-1)/9 +1>num){
            return "";
        }
        string ans(no9,'9');
        digits-=no9;
        if(digits>0) {
            char r='0'+rem;
            ans.push_back(r);
            digits--;
        }
        ans.append(digits,'0');
        return ans;
    }
};