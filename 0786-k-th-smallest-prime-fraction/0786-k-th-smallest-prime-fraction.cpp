class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            pq.push({-1.0 * arr[i]/arr.back(),{i,arr.size()-1}});
        }

        while(--k > 0){
            pair<int,int> temp = pq.top().second;
            pq.pop();
            temp.second--;
            pq.push({-1.0 * arr[temp.first]/arr[temp.second],{temp.first,temp.second}});
        }

        return {arr[pq.top().second.first],arr[pq.top().second.second]};
    }
};