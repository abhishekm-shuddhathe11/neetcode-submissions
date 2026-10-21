class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        if (n == 0) return 0;
        vector<pair<int, double>>cars;

        for(int i=0; i<n; i++){
            double time = (double)((target - position[i])/speed[i]);
            cars.push_back({ position[i], time});
        }

        sort(cars.rbegin(), cars.rend());  // Sorts Lexicographically

        int fleet = 1;
        double prevFleet = cars[0].second;
        
        for(int i=1; i<cars.size(); i++){
            double currentFleet = cars[i].second;

            if(currentFleet > prevFleet){
                fleet++;
                prevFleet = currentFleet;
            }
        }   
        return fleet;
    }
};
