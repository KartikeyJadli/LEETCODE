class Solution {
public:
    int bestClosingTime(string customers) {
        if(customers == "N"){
            return 0;
        }

        int n = customers.length(),sum = 0;
        vector<int> v(n + 1,0);

        for(int i=0;i<n;i++){
            v[i+1] = v[i];
            if(customers[i] == 'N'){
                v[i+1]++;
            }
        }

        int temp = v.back(),count = n;
        // cout << temp;

        for(int i=n-1;i>=0;i--){
            if(customers[i] == 'Y'){
                sum++;
            }

            if(temp >= v[i] + sum){
                count = i;
                temp = v[i] + sum;
            }
        }

        return count;
    }
};