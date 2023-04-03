class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        priority_queue<int> pq;
        priority_queue<int> extra;
        for(auto w : people){
            pq.push(w);
        }

        int count = 0;
        while(pq.size()){
            int w = pq.top();
            pq.pop();
            if(w < limit) {
                if(extra.size() && extra.top() >= w) {
                    extra.pop();
                }

                else {
                    extra.push(limit - w);
                    count++;
                }
            } 
            
            else {
                count++;
            }
        }

        return count;
    }
};