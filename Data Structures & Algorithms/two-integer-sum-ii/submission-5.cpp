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

// ============================================================================================== //

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s= 0, e = numbers.size()-1;

        while(s<e){
            int sum = numbers[s]+numbers[e];
            if(sum == target){
                return {s+1, e+1};
            }
            else if(sum < target){
                s++;
            }
            else
                e--;

        }
        return {};
    }
};


