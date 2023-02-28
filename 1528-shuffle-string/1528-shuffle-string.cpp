class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = "";
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        int n = s.length();
        for(int i=0;i<n;i++){
            pq.push({indices[i],s[i]});
        }

        while(!pq.empty()){
            str += pq.top().second;
            pq.pop();
        }

        return str;
    }
};