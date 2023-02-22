class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        pq.push(1);
        n = n - 1;
        long long int temp = 0;

        while(n--){
            temp = pq.top();
            pq.push(temp*2);
            pq.push(temp*3);
            pq.push(temp*5);
            pq.pop();

            while(pq.top() == temp){
                pq.pop();
            }
        }

        return pq.top();
    }
};