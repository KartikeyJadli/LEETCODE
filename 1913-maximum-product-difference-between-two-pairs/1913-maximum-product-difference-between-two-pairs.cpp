class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int> p1;
        priority_queue<int,vector<int>,greater<int>> p2;
        int prod1 = 1,prod2 = 1;
        for(auto x: nums){
            p1.push(x);
            p2.push(x);
        }

        int i = 2;
        while(i--){
            prod1 *= p1.top();
            p1.pop();
            prod2 *= p2.top();
            p2.pop();
        }

        return prod1 - prod2;
    }
};