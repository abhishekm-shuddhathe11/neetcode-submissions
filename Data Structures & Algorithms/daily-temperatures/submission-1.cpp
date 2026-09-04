#include<bits/stdc++.h>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>res(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( temperatures[j] > temperatures[i] ){
                res[i] = j-i;
                break;
            }
          }
        res[n-1] = 0;
        }
        return res;
    }
};
