class Solution {
public:
    typedef pair<int,int> Pii;
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& id, int k) {
        vector<int> v(k);
        unordered_set<string_view> p(begin(pf), end(pf)), n(begin(nf), end(nf));
        priority_queue<Pii> pq;
        
        for(int i=0; i<size(report);i++) {
            istringstream ss(report[i]);
            string s;
            int points = 0;
            while(ss >> s) {
                if(p.count(s)){
                    points += 3;
                }

                else if(n.count(s)){
                    points--;
                }
            }

            pq.emplace(-points, id[i]);
            if (pq.size() > k){
                pq.pop();
            }
        }

        for (int i = k-1; i >= 0; i--) {
            v[i] = pq.top().second, pq.pop();
        }
        return v;
    }
};