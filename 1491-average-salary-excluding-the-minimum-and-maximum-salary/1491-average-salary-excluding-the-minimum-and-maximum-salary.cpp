class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN,mn = INT_MAX;
        double result = 0.0;
        
        for(int i=0;i<salary.size();i++){
            mx = max(mx,salary[i]);
            mn = min(mn,salary[i]);

            result += salary[i];
        }

        result = result - mx - mn;
        cout << result;
        return result/(salary.size() - 2); 
    }
};