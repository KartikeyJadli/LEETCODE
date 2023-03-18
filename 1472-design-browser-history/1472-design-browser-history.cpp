class BrowserHistory {
    vector<string> v;
    int i = 0;
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }

    void visit(string url) {
        v.resize(i + 1);
        v.push_back(url);
        ++i;
    }

    string back(int steps) {
        return v[i = max(i - steps, 0)];
    }

    string forward(int steps) {
        return v[i = min(i + steps, (int)v.size() - 1)];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */