class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s;
        
        for(int num: nums) {
            s.insert(num);
        }

        int count = 0;
        for(int num: nums) {
            if(s.find(num + diff)  != s.end()  && s.find(num + diff + diff)  != s.end() ){
                count++;
            }
        }

        return count;
    }
};