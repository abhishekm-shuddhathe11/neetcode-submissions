// Pick / Not- Pick Approach

// TC = O(2^N+T/M) as a loose upper bound
// SC = O(N+T/M)

// TLE => IDK why

#include<bits/stdc++.h>
class Solution {
public:

    void solve(int i,vector<int>&candidates,set<vector<int>>&st,int  target,int n,vector<int>& output){
        if(i == n){
            if(target == 0){
                st.insert(output);
                }
                return;
            }

        if(candidates[i] <= target){
            output.push_back(candidates[i]);
            solve(i+1, candidates, st, target - candidates[i], n , output);
            output.pop_back();
        }
        solve(i+1, candidates, st, target, n , output);
    }

   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int> output;
        int n = candidates.size();

        solve(0, candidates, st, target,n, output);

        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

// =======================================================

// TC = Exponential; a loose upper bound is O(2^N+T/M)
// SC = (O(T/M))

// For Loop approach , there is only one Recursive Call

// class Solution {
// public:

//     void solve(int i,vector<int>&candidates,vector<vector<int>>&ans,int  target,int n,vector<int>& output) {

//             if(target == 0){
//                 ans.push_back(output);
//                 return;
//             }

//         for(int j=i; j<n; j++){

//             if(j>i && candidates[j] == candidates[j-1] ) continue;  //V V IMP

//             if(candidates[j] > target)  break;

//             output.push_back(candidates[j]);
//             solve(j+1, candidates, ans, target - candidates[j], n , output);
//             output.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
//         sort(candidates.begin(), candidates.end());

//         vector<vector<int>>ans;
//         vector<int> output;
//         int n = candidates.size();

//         solve(0, candidates, ans, target,n, output);
//         return ans;
//     }
// };
