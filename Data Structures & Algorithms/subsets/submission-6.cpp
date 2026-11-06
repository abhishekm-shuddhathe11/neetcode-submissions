class Solution {
public:
    void solve(int i, vector<int> & nums, vector<vector<int>> & ans, vector<int>& output){

        if( i >= nums.size() ) {
            ans.push_back(output);
            return;
        }

        output.push_back(nums[i]);
        solve(i+1, nums, ans, output);

        output.pop_back();
        solve(i+1, nums, ans, output);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;

        solve(0, nums, ans, output);
        return ans;
    }
};
