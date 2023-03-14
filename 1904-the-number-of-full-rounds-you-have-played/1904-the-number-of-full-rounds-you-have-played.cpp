class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int login = stoi(loginTime.substr(0,2)) * 60 + stoi(loginTime.substr(3));
        int logout = stoi(logoutTime.substr(0,2)) * 60 + stoi(logoutTime.substr(3));

        if(login > logout){
            logout += 60 * 24;
        }

        return max(0,logout/15 - (login + 14)/15);
    }
};