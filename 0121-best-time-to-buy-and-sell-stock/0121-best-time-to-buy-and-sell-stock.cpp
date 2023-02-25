class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = 0;
        int minPrice = INT_MAX;
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
          minPrice = min(minPrice, prices[i]);
          max1 = max(max1, prices[i] - minPrice);
        }
        
        return max1;
    }
};