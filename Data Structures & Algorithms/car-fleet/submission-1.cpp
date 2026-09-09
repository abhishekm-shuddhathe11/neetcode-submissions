class Car{
    public:
    int position;
    double timeToTarget;

    Car() {}

    Car(int position , double timeToTarget){
        this->position = position;
        this->timeToTarget = timeToTarget;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        
        if(n==0)
            return 0;

        vector<Car> cars(n);        // Car cars[] = new cars[];

        for(int i=0; i<n; i++){
            double timeTotarget = ( ( (target - position[i] ) * 1.0 ) / speed[i] );

            cars[i] = Car( position[i] , timeTotarget );
        }

        sort( cars.begin(), cars.end() , [](const Car & a, const Car &b){
            return a.position > b.position;
        });          // sort based on postion descending
    

        int ans = 1;
        double fleetTime = cars[0].timeToTarget;

        for(int i = 1; i < n; i++) {

            if(cars[i].timeToTarget > fleetTime) {
            ans++;
            fleetTime = cars[i].timeToTarget;
            }
        }
        return ans;
    }
};
