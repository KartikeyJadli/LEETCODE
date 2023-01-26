class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int sol = -1,mn = INT_MAX;
        
        for(int i=0;i<points.size();i++){
            if(points[i][0] == x || points[i][1] == y){
                cout << points[i][0] << " " << points[i][1] << endl;
                
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                
                cout << d << endl;
                
                if(d < mn){
                    mn = d;
                    sol = i;
                }
            }
        }
        
        return sol;
    }
};