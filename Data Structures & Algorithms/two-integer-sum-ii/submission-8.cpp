// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size();

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(numbers[i]+ numbers[j]==target ){
//                     return {i+1,j+1};
//                 }
//             }
//         }
//         return {};
//     }
// };

// =========================================================================================//

// Binary Search   

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();

        for(int i=0; i<n; i++){
            int need = target - numbers[i];

            int s = i+1 , e =n-1;
            while(s <=e){
                int mid = ( s + ((e-s)/2) );

                if(numbers[mid] == need){
                    return {i+1,mid+1};
                }
                else if(numbers[mid]<need){
                    s = mid+1;
                }
                else
                    e = mid-1;

            }
        }
        return {};
    }
};


// ============================================================================================== //

// Optimal Solution
// TC = O(n)    SC= O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int s= 0, e = numbers.size()-1;

//         while(s<e){
//             int sum = numbers[s]+numbers[e];
//             if(sum == target){
//                 return {s+1, e+1};
//             }
//             else if(sum < target){
//                 s++;
//             }
//             else
//                 e--;

//         }
//         return {};
//     }
// };


