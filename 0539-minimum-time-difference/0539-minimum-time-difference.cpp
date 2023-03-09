class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int diff = INT_MAX;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x: timePoints){
            int h = x[0] * 10 + x[1];
            int m = x[3]  * 10 + x[4];

            pq.push(60 * h + m);
            pq.push(60 * (h + 24) + m);
        }

        int temp = 0,curr = pq.top();
        pq.pop();

        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            diff = min(diff,abs(curr - temp));
            curr = temp;
        }
        
        return diff;
    }
};