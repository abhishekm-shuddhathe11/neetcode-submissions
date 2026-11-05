// Total TC = O(N!) * N
// Total SC = O(N)

// class Solution {
// public:

//     void solve(int i, vector<int>& nums, vector<vector<int>>& ans){

//         if(i == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         for(int j=i; j<nums.size(); j++){  // TC O(N)
//             swap(nums[i], nums[j]);
//             solve(i+1, nums, ans);
//             swap(nums[i], nums[j]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
        
//         vector<vector<int>> ans;
//         solve(0, nums, ans);  // O(N!)
//         return ans;
//     }
// };


// ===========================================================================================

class Solution {
public:

    void solve(int i,vector<bool>& freq, vector<int>& nums, vector<vector<int>>& ans, vector<int>& output){

        if(output.size() == nums.size() ){
            ans.push_back(output);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i] == true){
                freq[i] = true; 
                output.push_back(nums[i]);
                solve(i+1,freq, nums, ans, output);
                freq[i] = false;
                output.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> freq(nums.size(), false);
        solve(0,freq, nums, ans, output);
        return ans;
    }
};
