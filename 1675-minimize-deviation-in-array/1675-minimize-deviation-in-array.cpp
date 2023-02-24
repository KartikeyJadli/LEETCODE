class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX,diff = INT_MAX;

        for(auto x: nums){
            if(x % 2 == 1){
                x = x * 2;
            }

            mn = min(mn,x);
            pq.push(x);
        }

        while(pq.top() % 2 == 0){
            int mx = pq.top();
            pq.pop();

            diff = min(diff,mx-mn);
            mn = min(mn,mx/2);

            pq.push(mx/2);
        }

        return min(diff,pq.top()-mn);
    }
};