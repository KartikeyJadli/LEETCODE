class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> mp; 
        for(auto x: roads){
            mp[x[0]]++;
            mp[x[1]]++;
        }

        priority_queue<long long> pq;
        long long count = 0;
        for(auto x: mp){
            pq.push(x.second);
        }

        while(!pq.empty() && n){
            // cout << count << endl;
            count += n * pq.top();
            // cout << pq.top() << " " << count << endl;
            pq.pop();
            n--;
        }

        return count;
    }
};