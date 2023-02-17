class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long long count = 0;
        int n = time.size();

        vector<int> v(60,0);
        for(int i=0;i<n;i++){
            int r = time[i] % 60;
            v[r]++;
        }

        int m = 60;
        for(int i=1;i<m/2;i++){
            count += (long long)v[i] * v[m-i];
        }

        count += (long long)v[0] * (v[0] - 1)/2;
        count += (long long)v[30] * (v[30] - 1)/2;
        return count;
    }
};