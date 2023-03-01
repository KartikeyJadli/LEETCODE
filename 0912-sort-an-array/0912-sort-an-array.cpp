class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto x: nums){
            pq.push(x);
        }

        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }

        return v;
    }
};