class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size(),count = 0;
        priority_queue<int> p1,p2;

        for(int i=0;i<n;i++){
            p1.push(seats[i]);
            p2.push(students[i]);
        }

        while(!p1.empty() || !p2.empty()){
            count += (abs(p1.top() - p2.top()));
            p1.pop();
            p2.pop();
        }

        return count;
    }
};