class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> v;
        vector<int> v1;

        for(int i=0;i<n;i++){
            int idx = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin();  
            v1.push_back(idx + 1);
            
            if(idx == v.size())
                v.push_back(obstacles[i]);
            
            else{
                v[idx] = obstacles[i];
            }
        }
        
        return v1;
    }
};