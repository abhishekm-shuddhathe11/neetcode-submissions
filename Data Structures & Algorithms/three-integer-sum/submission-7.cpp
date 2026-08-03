// Brutte  "TIME LIMIT EXCEED (TLE)"  

// TC = Time: O(N³ × log M) (often written approximately as O(N³ log N) in interviews)
// SC = Space: O(M) for the set (excluding the output vector)

// #include<bits/stdc++.h>
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         vector<vector<int>> ans;
//         int n = nums.size();
//         set<vector<int>>st;

//         for(int i=0; i<n-2; i++){
//             for(int j=i+1; j<n-1; j++){
//                 for(int k=j+1; k<n; k++){

//                     vector<int>triplets;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         triplets = {nums[i], nums[j], nums[k]};
        
//                     sort(triplets.begin(), triplets.end());
//                     st.insert(triplets);
//                     }
//                 }
//             }
//         }

//         for(auto &triplet:st){
//             ans.push_back(triplet);
//         }
//         return ans;
//     }
// };


// ===========================================================================================================//

//Approach 2: Sorting + Hash Set (Better)
//TC =  O(^2)
//SC = O(N)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         int n = nums.size();
//         vector<vector<int>> ans;
//         set<vector<int>> st;

//         sort(nums.begin(), nums.end()); // Sort is not mandatory it runs w/o it perfectly.

//         for (int i = 0; i < n; i++) {

//             unordered_set<int> seen;

//             for (int j = i + 1; j < n; j++) {

//                 int need = -(nums[i] + nums[j]);

//                 if (seen.count(need)) {

//                     vector<int> triplet = {nums[i], need, nums[j]};
//                     sort(triplet.begin(), triplet.end());

//                     st.insert(triplet);
//                 }

//                 seen.insert(nums[j]);
//             }
//         }

//         for (const auto &triplet : st)
//             ans.push_back(triplet);

//         return ans;
//     }
// };

// ========================================================================================================= //

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>>st;

        for(int i=0;i<n-1;i++){

            int s=i+1 , e=n-1;
            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];

                vector<int> triplets;
                if(sum == 0){
                    triplets = {nums[i], nums[s], nums[e]}; 
                    sort(triplets.begin(), triplets.end());
                    st.insert(triplets);
                }
                if(sum <0){
                    s++;
                }
                else
                    e--;
            }
        }
        for(auto & p:st){
            ans.push_back(p);
        }
        return ans;
    }
};
