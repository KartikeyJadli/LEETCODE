class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<vector<int>, vector<vector<int>>> pq;   
        if(a){
            pq.push({a, 0});
        }

        if(b){
            pq.push({b, 1});
        }

        if(c){
            pq.push({c, 2});
        }

        string str = "";
        int prev = -1;

        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            int num = v[0],ch = v[1];
            str += ch + 'a';
            if(num > 1){
                if(prev == ch){
                    if(pq.empty()){
                        return str;
                    }

                    vector<int> next = pq.top(); 
                    pq.pop();
                    str += next[1] + 'a';
                    if(next[0] > 1){                        
                        pq.push({next[0]-1, next[1]});
                        
                    }

                    prev = next[1];
                    pq.push({num-1, ch});
                }
                
                else{
                    pq.push({num-1, ch});
                    prev = ch;
                }
            }
        }

        return str;
    }
};