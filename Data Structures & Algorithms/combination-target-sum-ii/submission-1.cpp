
class Solution {
public:

    void solve(int i,vector<int>&candidates,vector<vector<int>>&ans,int  target,int n,vector<int>& output){

            if(target == 0){
                ans.push_back(output);
                return;
            }

        for(int j=i; j<n; j++){

            if(j>i && candidates[j] == candidates[j-1]) continue;
            
            if(candidates[j] > target){
                break;
            }
            output.push_back(candidates[j]);
            solve(j+1, candidates, ans, target - candidates[j], n , output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int> output;
        int n = candidates.size();

        solve(0, candidates, ans, target,n, output);
        return ans;
    }
};
