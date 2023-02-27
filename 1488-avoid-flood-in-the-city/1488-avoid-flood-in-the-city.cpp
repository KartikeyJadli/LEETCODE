class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> nextFlood(n,-1);
        unordered_map<int,int> hm;

        for(int i=n-1;i>=0;i--){
            if(rains[i] > 0){
                if(hm.count(rains[i])){
                    nextFlood[i] = hm[rains[i]];
                }

                hm[rains[i]] = i;
            }
        }

        priority_queue<pair<int,int>> pq;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(rains[i] > 0){
                if(nextFlood[i] != -1){
                    pq.push(make_pair(-nextFlood[i],rains[i]));
                }
            }
            
            else{
                if(pq.size()){
                    pair<int,int> top=pq.top();
                    if(-top.first < i){
                        return vector<int>();
                    }

                    pq.pop();
                    ans[i] = top.second;
                }
                
                else{
                    ans[i] = 1;
                }
            }
        }

        return pq.size()==0 ? ans : vector<int>();
    }
};