class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> v;
        int i = 0;
        for(auto x: nums){
            pq.push(x);
        }

        while(!pq.empty() && pq.top() <= target){
            if(pq.top() == target){
                v.push_back(i);
            }
            
            i++;
            pq.pop();
        }

        return v;
    }
};