class Solution {
public:
    struct comp{
        bool operator()(string a,string b){
            if(a.size() == b.size()){
                return a < b;
            }

            return a.size() < b.size();
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,comp> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        } 

        string temp;
        while(k--){
            temp = pq.top();
            pq.pop();
        }

        return temp;
    }
};