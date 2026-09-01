// #include<bits/stdc++.h>
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         vector<int>ans; 
//         int i=0;
//         while( i+k <= n ){

//         int currWindowMax = INT_MIN;
//             for( int j=i; j< i+k ; j++){
//                 currWindowMax = max( currWindowMax , nums[j]);
//             }
//             ans.push_back(currWindowMax);
//             i++;
//         }
//         return ans;
//     }
// };



// Better Appraoch :

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> nums, int k){
        
        if(k==1){
            return nums;
        }

        vector<int>ans;
        int n =nums.size();
        
        multiset<int> st;

        for(int i=0; i<k; i++){
            st.insert(nums[i]);
        }
        ans.push_back( *prev(st.end()) );  

        int i=0;
        while(i+k < n){

        st.erase( st.find(nums[i]) );
        st.insert( nums[i+k] );

        ans.push_back( *prev(st.end()) );
        i++;
        }

    return ans;
    }   
};