// Pick / Not- Pick Approach

// TC = O(2^N+T/M) as a loose upper bound
// SC = O(N+T/M)

// class Solution {
// public:

//     void solve(int i,vector<int>&nums,vector<vector<int>>&ans,int  target,int n,vector<int>& output){
//         if(i == n){
//             if(target == 0){
//                 ans.push_back(output);
//                 }
//                 return;
//             }

//         // if(target == 0){             // It will also work 
//         //     ans.push_back(output);
//         //     return;
//         // }
//         // if(i == n){
//         //     return;
//         // }

//         // if(i == n && target == 0){        // IF you try to use this you will get "heap-buffer-overflow" ERROR
//         //         ans.push_back(output);
//         //         return;
//         //     }

//         if(nums[i] <= target){
//             output.push_back(nums[i]);
//             solve(i, nums, ans, target - nums[i], n , output);
//             output.pop_back();
//         }
//         solve(i+1, nums, ans, target, n , output);
//     }

//     vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
//         vector<vector<int>>ans;
//         vector<int> output;
//         int n = nums.size();

//         solve(0, nums, ans, target,n, output);
//         return ans;
//     }
// };

// ===============================

// TC = Exponential; a loose upper bound is O(2^N+T/M)
// SC = (O(T/M))

// For Loop approach 

class Solution {
public:

    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,int  target,int n,vector<int>& output){

            if(target == 0){
                ans.push_back(output);
                return;
            }

        for(int j=i; j<n; j++){
            
            if(nums[j] > target){
                break;
            }
            output.push_back(nums[j]);
            solve(j, nums, ans, target - nums[j], n , output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        vector<int> output;
        int n = nums.size();

        solve(0, nums, ans, target,n, output);
        return ans;
    }
};
