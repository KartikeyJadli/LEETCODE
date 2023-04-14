class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0,odd = 0,n = position.size();
        for(int i=0;i<n;i++){
            if(abs(position[i] - position[0])%2 == 0){
                even++;
            }

            else{
                odd++;
            }
        }

        return min(even,odd);
    }
};