class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> h;
    int l;
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(int i=0;i<nums.size();i++){
            h.push(nums[i]);
            while(h.size()>k){
                h.pop();
            }
        }
    }
    
    int add(int val) {
        h.push(val);
        while(h.size()>l){
            h.pop();
        }
        return h.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */