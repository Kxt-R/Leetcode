class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int> , greater<>> pq;
        while(n){
            int a=n%10;
            n/=10;
            pq.push(a);
            while(pq.size()>2){
                pq.pop();
            }
        }
        int x,y;
        x=pq.top();
        pq.pop();
        y=pq.top();
        return x*y;
    }
};