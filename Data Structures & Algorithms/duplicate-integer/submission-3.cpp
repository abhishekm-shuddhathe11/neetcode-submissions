// Brutte Force Solution
   //  Time Complexity = O(n²)  &&  Space Complexity = O(1)

// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
        
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[i]==nums[j])
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//=================================================

// Overall:

// Time: O(n log n)
// Space: Depends on the sorting implementation. For std::sort, it's typically O(log n) due to recursion stack.

// #include<bits/stdc++.h>
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
        
//         int n = nums.size();
//         sort(nums.begin(), nums.end() );
//            for(int i=0; i<n-1; i++){
//                 if(nums[i]==nums[i+1]){
//                 return true;
//                 }
//         }
//         return false;
//     }
// };


//======================================================================================================

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int>st;

        for (int x : nums){
            if(st.find(x) != st.end()){
                return true;
            }
            st.insert(x);

            }
        return false;
    }
};