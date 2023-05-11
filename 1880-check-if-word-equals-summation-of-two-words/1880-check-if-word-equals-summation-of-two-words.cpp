class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        long long int num1 = 0,num2 = 0,sum = 0;
        int n = firstWord.length(),m = secondWord.length();
        for(int i=0;i<n;i++){
            sum = sum * 10 + (firstWord[i] - 'a')%10;
        }

        num1 = sum;
        sum = 0;
        for(int i=0;i<m;i++){
            sum = sum * 10 + (secondWord[i] - 'a')%10;
        }

        num2 = sum;
        sum = 0;

        n = targetWord.length();
        for(int i=0;i<n;i++){
            sum = sum * 10 + (targetWord[i]-'a')%10;
        }

        cout << num1 << " " << num2 << " " << sum << endl;

        return num1 + num2 == sum;
    }
};