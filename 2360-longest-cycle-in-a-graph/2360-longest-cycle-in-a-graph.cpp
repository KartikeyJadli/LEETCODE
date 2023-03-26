class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int count = -1,n = edges.size();
        vector<pair<int,int>> v(n,{-1, -1});
        for(int i=0;i<n;i++)
            for(int j=i,d=0;j!=-1;j=edges[j]) {
                auto [dist,from] = v[j];
                if(dist == -1){
                    v[j] = {d++, i};
                }

                else {
                    if(from == i){
                        count = max(count, d - dist);
                    }

                    break;
                }
            }

        return count;
    }
};