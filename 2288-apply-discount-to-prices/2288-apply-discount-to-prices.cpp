class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n = sentence.size();
        string str;
        sentence += ' ';
        for(int i=0;i<n;i++){
            if(sentence[i] == '$'){
                if(i == 0 || sentence[i-1] == ' '){
                    i++;
                    double l = 0;
                    string d = "$";
                    if(i == n){
                        str += '$';
                        return str;
                    }

                    while(i < n && sentence[i] >= '0' && sentence[i] <= '9' && sentence[i] != ' ' || sentence[i] == '.'){
                        d += sentence[i];
                        l = l * 10 + sentence[i] - '0';
                        i++;
                    }

                    if(sentence[i]==' '&&l!=0){
                        double dis = (double)((double)(discount) / 100) * (double)l;
                        double newp = (double) l- dis;
                        stringstream out;
                    
                        out << std::fixed << std::setprecision(2) << newp;
                        str += '$';
                        str += out.str();
                        if(i == n){
                            break;
                        }
                    }

                    else{
                        str+=d;
                    }
                }
            }
            
            if(i==n){
                break;
            }

            str += sentence[i];
        }

        return str;
    }
};