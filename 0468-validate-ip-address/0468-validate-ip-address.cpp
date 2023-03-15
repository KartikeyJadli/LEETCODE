class Solution{
    public:    
    string validIPv6Chars = "0123456789abcdefABCDEF";
    string validIPAddress(string IP) {
        stringstream ssIP4(IP);
        stringstream ssIP6(IP);
        string token;
        int count_IP4 = 0;
        int count_IP6 = 0;
        if(IP.find('.') != string::npos){
            while(getline(ssIP4, token, '.'))
            {
                count_IP4++;
                if(token.size() == 0 ||token.size() > 3 )
                    return "Neither";
                for(int i = 0; i<token.size();i++)
                {
                    if(token[0] == '0' && token.size() > 1 || token[i]-'0' < 0 || token[i]-'0' > 9 )
                        return "Neither";
                }
                
                if(stoi(token) < 0 || stoi(token) > 255)
                    return "Neither";
            }
                if(IP[IP.size()-1] == '.')
                    return "Neither";
                if(count_IP4 == 4)
                    return "IPv4";
        }

        else if(IP.find(':') != string::npos)
        {
            while(getline(ssIP6, token, ':')){
                count_IP6++;
            if(token.size() == 0 || token.size() > 4 )
                return "Neither";
                else
                {
                    for(int i = 0; i<token.size();i++)
                    {
                        if(validIPv6Chars.find(token[i]) == string::npos)
                            return "Neither";
                    }
                }
        }
            
            if(IP[IP.size()-1] == ':')
                return "Neither";
            if(count_IP6 == 8)
                return "IPv6";
        }
        
        return "Neither";
    }
};