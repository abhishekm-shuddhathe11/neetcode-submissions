#include<limits.h>
#include<bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0 , minPrice = INT_MAX;
        for(int i=0; i<n-1; i++){
            int buy = prices[i];
            for(int j=i+1; j<n; j++){
                int sell = prices[j] - buy;
                maxProfit = max(maxProfit , sell);
            }
        }
        return maxProfit;
    }
};
