class Solution {
public:
    struct compare{
        bool operator()(const pair<int,string> &a,const pair<int,string> &b){
            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first > b.first;
        }
    };

    int words(string &str){
        int n = str.length(),count = 0;
        for(int i=0;i<n;i++){
            if(str[i] == ' '){
                count++;
            }
        }

        return count + 1;
    }

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        
        for(int i=0;i<n;i++){
            int count = words(messages[i]);
            mp[senders[i]] += count;    
        }

        for(auto x: mp){
            pq.push({x.second,x.first});

            if(pq.size() > 1){
                pq.pop();
            }
        }

        
        return pq.top().second;
    }
};