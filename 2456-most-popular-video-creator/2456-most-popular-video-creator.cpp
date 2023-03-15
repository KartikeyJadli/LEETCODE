class Solution {
public:
    typedef long long ll;
    struct compare{
        bool operator()(pair<string,ll> &a,pair<string,ll> &b){
            if(a.second == b.second){
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,ll> mp;
        map<string,priority_queue<pair<string,ll>,vector<pair<string,ll>>,compare>> mp2;
        int n = creators.size();
        ll mx = INT_MIN;
        for(int i=0;i<n;i++){
            mp[creators[i]] += views[i];
            mx = max(mx,mp[creators[i]]);
            mp2[creators[i]].push({ids[i],views[i]});
        }

        vector<vector<string>> v;
        for(auto x: mp2){
            if(mp[x.first] == mx){
                v.push_back({x.first,mp2[x.first].top().first});
            }
        }

        return v;
    }
};