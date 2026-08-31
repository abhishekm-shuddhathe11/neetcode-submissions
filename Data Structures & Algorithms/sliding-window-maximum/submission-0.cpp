#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans; 
        int i=0;
        while( i+k <= n ){

        int currWindowMax = INT_MIN;
            for( int j=i; j< i+k ; j++){
                currWindowMax = max( currWindowMax , nums[j]);
            }
            ans.push_back(currWindowMax);
            i++;
        }
        return ans;
    }
};
