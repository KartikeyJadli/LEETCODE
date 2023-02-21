class Solution {
public:
    struct compare{
        bool operator()(const pair<int,string> a,const pair<int,string> b){
            if(a.first < b.first || (a.first == b.first) && (a.second > b.second)){
                return true;
            }

            return false;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.size() == 1 && k == 1){
            return words;
        }
        
        map<string,int> mp;
        
        for(auto x: words){
            mp[x]++;
        }

        for(auto x: mp){
            cout << x.first << " " << x.second << endl;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> p;
        vector<string> v;
        for(auto i: mp){
            p.push({i.second,i.first});
        }
        
        while(k--){
            v.push_back(p.top().second);
            p.pop();
        }
        
        // sort(v.begin(),v.end());
        return v;
    }
};