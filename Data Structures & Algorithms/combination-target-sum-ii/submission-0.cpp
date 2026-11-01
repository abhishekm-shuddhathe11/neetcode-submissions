
class Solution {
public:

    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,int  target,int n,vector<int>& output){

            if(target == 0){
                ans.push_back(output);
                return;
            }

        for(int j=i; j<n; j++){

            if(j>i && arr[j] == arr[j-1]) continue;
            
            if(nums[j] > target){
                break;
            }
            output.push_back(nums[j]);
            solve(j+1, nums, ans, target - nums[j], n , output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        vector<int> output;
        int n = nums.size();

        solve(0, nums, ans, target,n, output);
        return ans;
    }
};
