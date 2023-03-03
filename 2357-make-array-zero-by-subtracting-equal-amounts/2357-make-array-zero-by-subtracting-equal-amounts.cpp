class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto x: nums){
            pq.push(x);
            
        }

        int count = 0,num = 0;
        while(!pq.empty()){
            if(pq.top() == 0){
                pq.pop();
            }
            
            else{
                int temp = pq.top() - num;
                if(temp != 0){
                    num = temp + num;
                    count++;
                }

                pq.pop();
            }
        }

        // while(!pq.empty()){
        //     cout << pq.top() << " ";
        //     pq.pop();
        // }
        return count;
    }
};