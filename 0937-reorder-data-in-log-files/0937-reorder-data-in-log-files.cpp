class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, string> m;
        vector<string> dig;
        auto f = [](auto& a, auto&b){
            if (a.first == b.first){
                return a.second > b.second;
            }
            
            return a.first > b.first;
        };

        priority_queue<pair<string, string>, vector<pair<string, string>>, decltype(f)> pq(f);
        stringstream ss;
        string id, lg, log;
        
        for (auto l : logs){
            ss << l;
            ss >> id;
            getline(ss, log);
            if (log[log.size()-1] - '0' >= 0 && log[log.size()-1] - '0' <= 9 ){
                dig.push_back(l);
            } else{
                pq.push(make_pair(log, id));
            }
            ss.clear();
        }
        
        vector<string> ans;
        
        while (!pq.empty()){
            auto p = pq.top();
            ans.push_back(p.second + p.first);
            pq.pop();
        }
        
        ans.insert(ans.end(), dig.begin(), dig.end());
        return ans;
    }
};