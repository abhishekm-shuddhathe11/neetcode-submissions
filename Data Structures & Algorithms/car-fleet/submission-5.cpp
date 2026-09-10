// class Car{
//     public:
//     int position;
//     double timeToTarget;

//     Car() {}

//     Car(int position , double timeToTarget){
//         this->position = position;
//         this->timeToTarget = timeToTarget;
//     }
// };

// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
//         int n = speed.size();
        
//         if(n==0)
//             return 0;

//         vector<Car> cars(n);        // Car cars[] = new cars[];

//         for(int i=0; i<n; i++){
//             double timeTotarget = ( ( (target - position[i] ) * 1.0 ) / speed[i] );

//             cars[i] = Car( position[i] , timeTotarget );
//         }

//         sort( cars.begin(), cars.end() , [](const Car & a, const Car &b){
//             return a.position > b.position;
//         });          // sort based on postion descending
    

//         int ans = 1;
//         double fleetTime = cars[0].timeToTarget;

//         for(int i = 1; i < n; i++) {

//             if(cars[i].timeToTarget > fleetTime) {
//             ans++;
//             fleetTime = cars[i].timeToTarget;
//             }
//         }
//         return ans;
//     }
// };


// ============================================================================

//  TC = O(N log N)
//  SC = O(N)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {

//         int n = speed.size();

//         if (n == 0)
//             return 0;

//         vector<pair<int, double>> cars;

//         // position + timeToTarget
//         for (int i = 0; i < n; i++) {

//             double timeToTarget =
//                 ((target - position[i]) * 1.0) / speed[i];

//             cars.push_back({position[i], timeToTarget});
//         }

//         // Sort based on position descending
//         sort(cars.begin(), cars.end(),
//              [](const pair<int, double>& a,
//                 const pair<int, double>& b) {

//                  return a.first > b.first;
//              });

//         int ans = 1;

//         // Time of the fleet immediately ahead
//         double fleetTime = cars[0].second;

//         for (int i = 1; i < n; i++) {

//             // This car cannot catch the fleet ahead
//             if (cars[i].second > fleetTime) {

//                 ans++;

//                 // This car becomes a new fleet
//                 fleetTime = cars[i].second;
//             }

//             // else:
//             // current car catches the fleet ahead
//             // so nothing needs to be done
//         }

//         return ans;
//     }
// };

// ======================================================================================================

//  TC  = O(Nlog N)
//  SC  = O(N)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = speed.size();

        if (n == 0)
            return 0;

        vector<pair<int, double>> cars;

        // position + timeToTarget
        for (int i = 0; i < n; i++) {

            double timeToTarget =
                ((target - position[i]) * 1.0) / speed[i];

            cars.push_back({position[i], timeToTarget});
        }

        // Sort based on position descending
        sort(cars.begin(), cars.end(),
             [](const pair<int, double>& a,
                const pair<int, double>& b) {

                 return a.first > b.first;
             });

        stack<double>st;
        // Time of the fleet immediately ahead
        st.push(cars[0].second);

        for (int i = 1; i < n; i++) {

            double currentTime = cars[i].second;

            if(currentTime > st.top()){
                st.push(currentTime);
            }
        }
        return st.size();
    }
};

