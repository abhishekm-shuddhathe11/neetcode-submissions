// Brutte   TC = O(N^2)  SC = O(1)

// #include<limits.h>
// #include<bits/stdc++.h>
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int n = prices.size();
//         int maxProfit = 0;

//         for(int i=0; i<n-1; i++){
//             int buy = prices[i];

//             for(int j=i+1; j<n; j++){
//                 int sell = prices[j] - buy;
//                 maxProfit = max(maxProfit , sell);
//             }
//         }
//         return maxProfit;
//     }
// };

// ========================================================================================================//

#include<bits/stdc++.h>
class Solution {
public:

    vector<int> prefixMin(vector<int>& nums, int n){
        vector<int> ans(n);
        int prefixmin = nums[0];
        for(int i=0; i<n; i++){
            prefixmin = min(nums[i] , prefixmin );
            ans[i] = prefixmin;
        }
        return ans;
    }

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<int> prefix = prefixMin(prices , n);
        int maxprofit = 0;

        for(int i=0; i<n; i++){
            maxprofit = max(maxprofit , prices[i] - prefix[i]);
        }
        return maxprofit;
    }
};

