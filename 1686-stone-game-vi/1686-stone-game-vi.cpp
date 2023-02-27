class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int N = aliceValues.size();
        priority_queue<pair<int, int>> q;

        for(int i = 0; i < N; i++) {
            q.push({(aliceValues[i] + bobValues[i]), i});
        }

        int alice_sum = 0;
        int bob_sum = 0;
        int turn = 0;
        
        while(q.size()) {
            auto p = q.top();
            q.pop();
            if (turn == 0) {
                alice_sum += aliceValues[p.second];
            }
            
            else {
                bob_sum += bobValues[p.second];
            }

            turn = turn ^ 1;
        }

        if (alice_sum == bob_sum) {
            return 0;
        } 
        
        else if (alice_sum > bob_sum) {
            return 1;
        }

        return -1;
    }
};