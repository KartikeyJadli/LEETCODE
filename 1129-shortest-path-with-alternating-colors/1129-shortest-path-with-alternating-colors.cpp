class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> cons;
        cons.resize(2*n);
            
        for(auto& x: red_edges) cons[x[0]].push_back( n + x[1] );
        for(auto& x: blue_edges) cons[n+x[0]].push_back(x[1] );
       
        vector<int> v, b, b2, out;

        out.resize(n);
        v.resize(2*n);
        fill(v.begin(), v.end(), 1e9);
        
        b.push_back(0);
        b.push_back(n);
        int i = 0;
        while(b.size()){
            while(b.size()){
                int d= b.back();
                b.pop_back();

                if(v[d]!= 1e9) continue;
                
                for(auto j: cons[d]){
                    if(v[j]==1e9){
                        b2.push_back(j);
                    }
                }

                v[d]= i;
            }
                
            ++i;    
            swap(b, b2);
        }

        for(int i=0; i<n; ++i){
            out[i]= min(v[i], v[i+n]);
            if(out[i]==1e9) out[i] =-1;
        }
      
        return out;
    }
};