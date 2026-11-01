class Solution {
public:

    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,int  target,int n,vector<int>& output){
        
        if(target == 0){
    ans.push_back(output);
    return;
}

if(i == n){
    return;
}

        // if(i == n && target == 0){        // IF you try to use this you will get "heap-buffer-overflow" ERROR
        //         ans.push_back(output);
        //         return;
        //     }

        if(nums[i] <= target){
            output.push_back(nums[i]);
            solve(i, nums, ans, target - nums[i], n , output);
            output.pop_back();
        }
        solve(i+1, nums, ans, target, n , output);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        vector<int> output;
        int n = nums.size();

        solve(0, nums, ans, target,n, output);
        return ans;
    }
};
