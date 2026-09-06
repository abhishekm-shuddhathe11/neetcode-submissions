//Brutte Approach     TC = O(N)    SC = O(1)  => Auxillary    if Output space included then O(N)

// #include <vector>
// class Solution{
//     public:
// std::vector<int> productExceptSelf(const std::vector<int>& nums) {
//     int n = nums.size();
//     std::vector<int> answer(n, 1);

//     for (int i = 0; i < n; ++i) {
//         int currentProduct = 1;
//         for (int j = 0; j < n; ++j) {
//             if (i != j) { // Skip the current element
//                 currentProduct *= nums[j];
//             }
//         }
//         answer[i] = currentProduct;   // Assigning is best rather than answer.push_back(currentProduct)  doesn't works
//     }

//     return answer;
// }
// };


//=======================================================================//
                  // Division Approach

// TC = O(N)    But Division is inot allowed 

//Brutte Approach     TC = O(N)    SC = O(1)  => Auxillary    if Output space included then O(N)

// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(const vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);

//         int zeroCount = 0;
//         int product = 1;

//         // Count zeros and compute product of non-zero elements
//         for (int num : nums) {
//             if (num == 0) {
//                 zeroCount++;
//             } else {
//                 product *= num;
//             }
//         }

//         if (zeroCount > 1) {
//             return ans;
//         }

//         else if (zeroCount == 1) {
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] == 0) {
//                     ans[i] = product;
//                     // break;    // it not mandotory
//                 }
//             }
//             return ans;
//         }
//         else {
//             for (int i = 0; i < n; i++) {
//                 ans[i] = product / nums[i];
//             }
//         }

//         return ans;
//     }
// };

//=================================================================================================//

         // using Prefix & Suffix Array //  => Overal TC = SC =O(N)

// #include <bits/stdc++.h>
// class Solution{
// public:

// vector<int> prefixArray(vector<int>& nums, int n){
//     vector<int> prefix(nums.size());
    
//     prefix[0] = 1;
//     for(int i=1; i<n; i++){
//         prefix[i] = prefix[i-1] * nums[i-1];
//     }
//     return prefix;
// }

// vector<int> suffixArray(vector<int>& nums, int n){
//     vector<int> suffix(nums.size());
    
//     suffix[n-1] = 1;
//     for(int i=n-2; i>=0; i--){
//         suffix[i] = suffix[i+1] * nums[i+1];
//     }
//     return suffix;
// }

// vector<int> productExceptSelf(vector<int>& nums) {
//    int n = nums.size();
   
//     vector<int> ans(nums.size());

//         vector<int> prefix = prefixArray(nums,n);
//         vector<int> suffix = suffixArray(nums,n);
        
//         for(int i=0; i<n; i++){
//             ans[i] = prefix[i] * suffix[i];
//         } 
//     return ans;
//     }
// };



//=========================================================================================//

// The Most Optimal Solution , Instead of creating 2 Extra Spaces for Prefix & Suffix we store them simply in Running variables 


#include <bits/stdc++.h>
class Solution{
public:
vector<int> productExceptSelf(vector<int>& nums) {
   int n = nums.size();
    vector<int> ans(nums.size());
    
        int prefixProduct = 1;
        for(int i=0; i<n; i++){
            ans[i] = prefixProduct;
            prefixProduct *= nums[i];
        } 

        int suffixProduct = 1;
        for(int j=n-1; j>=0; j--){
            ans[j] *= suffixProduct;
            suffixProduct *= nums[j];
        }
    return ans;
    }
};
