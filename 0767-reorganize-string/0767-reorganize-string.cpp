class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        priority_queue<pair<int,char>> pq;

        string str = "";
        pair<int,char> prep{0,'0'},null{0,'0'};

        for(auto x: s){
            mp[x]++;
        }

        for(auto x: mp){
            pq.push({x.second,x.first});
        }

        while(pq.size() || prep != null){
            if(!pq.size() && prep != null){
                return "";
            }

            auto[fre,ch] = pq.top();
            pq.pop();

            str += ch;
            fre--;

            if(prep != null){
                pq.push(prep);
                prep = null;
            }

            if(fre){
                prep = make_pair(fre,ch);
            }
        }

        return str;
    }
};