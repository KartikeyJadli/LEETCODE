class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto i: nums){
            pq.push(i);
        }

        int temp = 0;
        while(k--){
            temp = pq.top();
            pq.pop();
        }

        return temp;
    }
};