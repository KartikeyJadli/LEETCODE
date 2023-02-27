class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x : arr) {
            mp[x]++;
        }
        
        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        int count = 0, removed = 0, half = arr.size() / 2;
        do {
            count++;
            removed += pq.top();
            pq.pop();            
        } while (removed < half);

        return count;
    }
};