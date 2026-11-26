class Solution {
public:
    void solve(int i, vector<int> & nums, vector<vector<int>> & ans, vector<int>& output){

        ans.push_back(output);

        // if( i >= nums.size() ) {
        //     ans.push_back(output);
        //     return;
        // }

        for(int j=i; j< nums.size(); j++) {

        if( j>i && nums[j] == nums[j-1] )  continue;

        output.push_back(nums[j]);
        solve(j+1, nums, ans, output);
        output.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());

        solve(0, nums, ans, output);
        return ans;
    }
};

