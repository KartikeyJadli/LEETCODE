class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // nth_element(points.begin(),points.begin() + k,points.end(), [](vector<int>& a, vector<int>& b) {
        //     return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        // });

        // return vector<vector<int>>(points.begin(),points.begin() + k);
        
        vector<vector<int>> v;
        map<vector<int>,int> mp;
        vector<pair<int,pair<int,int>>> v1;

        for(auto x: points){
            int diff = x[0]*x[0] + x[1]*x[1];
            cout << diff << endl; 
            v1.push_back({diff,{x[0],x[1]}});
        }

        sort(v1.begin(),v1.end());

        for(int i=0;i<k;i++){
            v.push_back({v1[i].second.first,v1[i].second.second});
        }

        return v;
    }
};
