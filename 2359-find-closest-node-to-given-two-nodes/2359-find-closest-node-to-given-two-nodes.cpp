class Solution {
public:
    /* Traverse the path for node1 from node1, and record the distance from it to each node that it could reach.
       Do the same thing for node2. If both node1 and node2 could reach the same node, try to update the result.
    */
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int n1can[n];
        fill_n(n1can, n, -1);
        
        int cnt = 0;
        for (; node1 != -1; node1 = edges[node1]) {
            if (n1can[node1] != -1) break; // cycle
			
            n1can[node1] = cnt++;
        }
        
        bool vis[n];
        fill_n(vis, n, false);
        int ans = -1;
        int bestcnt = 0;
        cnt = 0;
        for (; node2 != -1; node2 = edges[node2], cnt++) {
            if (vis[node2]) 
                break; // cycle
			
            vis[node2] = true;
            if (n1can[node2] != -1) {
                int curcnt = max(cnt, n1can[node2]);
                if (ans == -1 || curcnt < bestcnt || (curcnt == bestcnt && node2 < ans)) {
                    ans = node2;
                    bestcnt = curcnt;
                }
            }
        }
        
        return ans;
    }
};