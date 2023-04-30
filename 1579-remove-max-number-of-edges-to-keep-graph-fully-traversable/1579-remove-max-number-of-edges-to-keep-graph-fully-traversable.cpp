class Solution {
    vector<int> pa, pb; // roots list for Alice & Bob seperately
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        pa.resize(n + 1), pb.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            pa[i] = pb[i] = i;
        }
		
        // res: Redundant edges 
        int res = 0;
        int a_group = n, b_group = n;
        
        for (auto& e: edges) {
            int t = e[0], x = e[1], y = e[2];
            // Prioritize type3 edges
            if (t == 3) {
                int pax = find(x, pa), pay = find(y, pa), pbx = find(x, pb), pby = find(y, pb);
                if (pax != pay) {
                    pa[pax] = pay;
                    pb[pbx] = pby;
                    --a_group, --b_group;
                } else {
                    ++res;
                }
            }
        }
        
        for (auto& e: edges) {
            int t = e[0], x = e[1], y = e[2];
            if (t == 1) {
                int pax = find(x, pa), pay = find(y, pa);
                if (pax != pay) {
                    pa[pax] = pay;
                    --a_group;
                } else {
                    ++res;
                }
            } else if (t == 2) {
                int pbx = find(x, pb), pby = find(y, pb);
                if (pbx != pby) {
                    pb[pbx] = pby;
                    --b_group;
                } else {
                    ++res;
                }
            }
        }
        if (a_group > 1 || b_group > 1) {
            return -1;
        }
        return res;
    }
    
private:
    int find(int a, vector<int> &p) {
        if (p[a] != a) {
            p[a] = find(p[a], p);
        }
        return p[a];
    }
};