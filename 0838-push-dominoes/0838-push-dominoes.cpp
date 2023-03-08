class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        while(1){
            string old = dominoes, left = dominoes, right = dominoes;
            for(int i=0;i<n;i++){
                if(left[i] == 'L'){
                    if(i == 0 || left[i - 1] != '.'){
                        continue;
                    }

                    if(i - 1 > 0 && left[i - 2] == 'R'){
                        continue;
                    }

                    left[i - 1] = 'L';
                }
            }

            for (int i=n-1;i>=0;i--) {
                if (right[i] == 'R'){
                    if(i == n - 1 || right[i + 1] != '.'){
                        continue;
                    }

                    if(i + 2 < n && right[i + 2] == 'L'){
                        continue;
                    }

                    right[i + 1] = 'R';
                }
            }

            for(int i=0;i<n;i++){
                if(left[i] == 'L'){
                    dominoes[i] = 'L';
                }

                if(right[i] == 'R'){ 
                    dominoes[i] = 'R';
                }
            }

            if(dominoes == old){
                break;
            }
        }

        return dominoes;
    }
};