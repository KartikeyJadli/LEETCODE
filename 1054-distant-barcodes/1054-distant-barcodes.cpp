class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int i,j,k;
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        
        for(i=0;i<n;i++){
            mp[barcodes[i]]++;
        }
        
        for(auto it: mp){
            pq.push(make_pair(it.second,it.first));
        }
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);

            if(pq.empty()){
                break;
            }
            auto q = pq.top();
            pq.pop();
            ans.push_back(q.second);
            if(p.first > 1){
                pq.push(make_pair(p.first-1,p.second));
            }
            if(q.first > 1){
                pq.push(make_pair(q.first-1,q.second));
            }
        }
        
        return ans;
    }
};