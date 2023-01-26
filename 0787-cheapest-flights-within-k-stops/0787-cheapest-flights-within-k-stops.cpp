class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> v(n,numeric_limits<int> :: max());
        v[src] = 0;
        
        for(int i=0;i<=k;i++){
            vector<int> v1(v);
            
            for(auto &x: flights){
                if(v[x[0]] != numeric_limits<int> :: max()){
                    v1[x[1]] = min(v1[x[1]],v[x[0]] + x[2]);
                }
            }
            
            v = v1;
        }
        
        if(v[dst] == numeric_limits<int> :: max()){
            return -1;
        }
        
        return v[dst];
    }
};