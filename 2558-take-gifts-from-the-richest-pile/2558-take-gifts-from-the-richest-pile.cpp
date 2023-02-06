class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        // vector<int> v;
        long long temp = 0;
        int j = 0;
        for(int i=0;i<k;i++){
            temp = *max_element(gifts.begin(),gifts.end());
            j = max_element(gifts.begin(),gifts.end()) - gifts.begin();
            temp = sqrt(temp);
            cout << j << endl;
            gifts[j] = temp;
        }

        for(int i=0;i<gifts.size();i++){
            sum += gifts[i];
        }   

        return sum;
    }
};