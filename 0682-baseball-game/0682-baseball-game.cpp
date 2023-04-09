class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        int n = operations.size();

        for(int i=0;i<n;i++){
            if(operations[i] == "C"){
                v.pop_back();
            }

            else if(operations[i] == "D"){
                int s = 2 * v.back();
                v.push_back(s);
            }

            else if(operations[i] == "+"){
                int n = v.size();
                v.push_back(v[n-1] + v[n-2]);
            }

            else{
                v.push_back(stoi(operations[i]));
            }
        }

        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum += v[i];
        }

        return sum;
    }
};