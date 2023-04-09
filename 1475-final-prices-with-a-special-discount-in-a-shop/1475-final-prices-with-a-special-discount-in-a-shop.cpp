class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        int n = prices.size(),mx = 0;

        for(int i=0;i<n;i++){
            mx = 0;
            for(int j=i+1;j<n;j++){
                if(prices[j] <= prices[i]){
                    mx = max(mx,prices[j]);
                    break;
                }
            }

            if(mx == 0){
                v.push_back(prices[i]);
            }

            else{
                v.push_back(abs(prices[i] - mx));
            }
        }

        return v;
    }
};