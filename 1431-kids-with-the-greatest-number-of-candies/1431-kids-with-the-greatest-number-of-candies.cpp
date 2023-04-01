class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int temp = *max_element(candies.begin(),candies.end());
        vector<bool> v;
        int n = candies.size();

        for(int i=0;i<n;i++){
            if((candies[i] + extraCandies) >= temp){
                v.push_back(true);
            }

            else{
                v.push_back(false);
            }
        }
        return v;
    }
};