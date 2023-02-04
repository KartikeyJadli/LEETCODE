class ParkingSystem {
public:
    vector<int> v;
    ParkingSystem(int big, int medium, int small) {
        v.push_back(0);
        v.push_back(big);
        v.push_back(medium);
        v.push_back(small);
    }
    
    bool addCar(int carType) {
        if(!v[carType]){
            return false;
        }

        v[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */