class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size(), ans = 0, sum = gas[0]-cost[0];
        for(int i=1,mSum = 0;i<n;sum += gas[i] - cost[i], ++i){ 
            if(sum < mSum) {
                mSum = sum;
                ans = i;
            }
        }   

        return sum >= 0 ? ans:-1;
    }
};