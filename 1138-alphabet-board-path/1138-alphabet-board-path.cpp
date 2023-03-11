class Solution {
public:
    string alphabetBoardPath(string target) {
        string str = "";
        int r = 0,c = 0;
        for(auto x: target){
            auto it = (x - 'a') / 5;
            auto it1 = (x - 'a') % 5;
            for(auto found{false}; !found;){
                if(r > it){
                    --r;
                    str.push_back( 'U' );
                }
                
                else if(c < it1){
                    ++c;
                    str.push_back( 'R' );
                }
                
                else if(c > it1){
                    --c;
                    str.push_back( 'L' );
                }

                else if(r < it){
                    ++r;
                    str.push_back( 'D' );
                }
                
                else{
                    found = true;
                    str.push_back( '!' );
                }
            }
        }

        return str;
    }
};