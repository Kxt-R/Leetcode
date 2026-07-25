class Solution {
public:
    //general k digit product solution 
    int maxProduct(int n) {
        int k=2; // here for question k==2
        priority_queue<int,vector<int> , greater<>> pq;
        while(n){
            int a=n%10;
            n/=10;
            pq.push(a);
            while(pq.size()>k){ 
                pq.pop();
            }
        }
        int x=1;
        while(!pq.empty()){
            x=x*pq.top();
            pq.pop();
        }
        return x;
    }
};