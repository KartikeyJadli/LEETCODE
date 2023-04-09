class Solution {
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int count = 0,i = 0,n = heights.size();
        for(auto x: heights){
            pq.push(x);
        }   

        while(!pq.empty()){
            if(pq.top() != heights[i]){
                count++;
            }

            i++;
            pq.pop();
        }

        return count;
    }
};