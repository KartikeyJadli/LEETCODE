class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dist = 0;
        sort(trips.begin(),trips.end(),[&](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });

        bool flag = true;
        vector<pair<int,int>> v;
        int n = trips.size();

        // for(auto x: trips){
        //     cout << x[0] << " " << x[1] << " " << x[2] << endl;
        // }
        
        for(auto x: trips){
            dist = x[1];

            for(int i=0;i<v.size();i++){
                if(v[i].second != -1 && v[i].second <= dist){
                    capacity += v[i].first;
                    v[i].first = -1;
                    v[i].second = -1;
                }
            }

            if(capacity >= x[0]){
                capacity -= x[0];
                v.push_back({x[0],x[2]});
            }

            else{
                flag = false;
                break;
            }
        }

        return flag;
    }
};