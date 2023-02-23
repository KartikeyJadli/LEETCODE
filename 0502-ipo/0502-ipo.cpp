class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        multiset<pair<int,int>> ms;
        int n = profits.size();

        for(int i=0;i<n;i++){
            if(profits[i] > 0){
                if(capital[i] <= w){
                    pq.push(profits[i]);
                }

                else{
                    ms.emplace(capital[i],profits[i]);
                }
            }
        }

        while(k-- && pq.size()){
            w += pq.top();
            pq.pop();

            for(auto it=ms.begin();ms.size() && it->first <= w;it=ms.erase(it)){
                pq.push(it->second);
            }

        }

        return w;
    }
};