class SummaryRanges {
public:
    set<int> st;
    void addNum(int val) {
        st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        if (st.empty()) {
            return {};
        }

        vector<vector<int>> v;
        int left = -1, right = -1;
        for (int value : st) {
            if (left < 0) {
                left = right = value;
            } 
            
            else if (value == right + 1) {
                right = value;
            }
            
            else {
                v.push_back({left, right});
                left = right = value;
            }
        }
        
        v.push_back({left, right});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */