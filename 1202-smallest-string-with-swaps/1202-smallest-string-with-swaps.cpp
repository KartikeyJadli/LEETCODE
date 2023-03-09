class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = s.size();
        if (n == 0) {
            return s;
        }
        
        vector<vector<int>> v(n);
        vector<bool> v1(n, false);
        for(auto &x: pairs) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }

        for (int i=0;i<n;i++) {
            if (v1[i] == false) {
                vector<int> indices;
                string str = "";
                dfs(i,indices,v,v1);
                for(int &idx : indices) {
                    str += s[idx];
                }
                sort(str.begin(),str.end());
                sort(indices.begin(),indices.end());
                int j = 0;
                for (int &idx : indices) {
                    s[idx] = str[j++];
                }
            }
        }

        return s;
    }
    
    void dfs(int cur, vector<int> &indices, vector<vector<int>> &graph, vector<bool> &seen) {
        seen[cur] = true;
        indices.push_back(cur);
        for (int &neigh : graph[cur]) {
            if (seen[neigh] == false) {
                dfs(neigh, indices, graph, seen);
            }
        }
    }
};