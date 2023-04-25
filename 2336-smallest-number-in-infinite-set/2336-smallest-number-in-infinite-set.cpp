class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        s.clear();
        for(int i=1;i<=1000;i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int pop = *s.begin();
        s.erase(pop);

        return pop;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */