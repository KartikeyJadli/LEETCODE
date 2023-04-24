class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;

        for(auto i: stones){
            p.push(i);
        }

        int temp,temp2;
        while(p.size() != 1){
            temp = p.top();
            p.pop();
            temp2 = p.top();
            p.pop();

            p.push(temp - temp2);
        }

        return p.top();
    }
};