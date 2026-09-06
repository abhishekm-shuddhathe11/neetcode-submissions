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

// #include<bits/stdc++.h>
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int> nums, int k){
        
//         if(k==1){
//             return nums;
//         }

//         vector<int>ans;
//         int n =nums.size();
        
//         multiset<int> st;

//         for(int i=0; i<k; i++){
//             st.insert(nums[i]);
//         }
//         ans.push_back( *prev(st.end()) );  

//         int i=0;
//         while(i+k < n){

//         st.erase( st.find(nums[i]) );
//         st.insert( nums[i+k] );

//         ans.push_back( *prev(st.end()) );
//         i++;
//         }

//     return ans;
//     }   
// };



// Optimal Solution 

#include<bits/stdc++.h>
class Solution{
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;
        deque<int>dq;

        for(int i=0; i<n; i++){
            
            if( !dq.empty() && dq.front() <= i-k ){   // dq.front() < i-k+1
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]< nums[i] ){
                dq.pop_back();
            }

            dq.push_back(i);  // To add current Index

            if(i>= k-1){
                ans.push_back( nums[dq.front()]);
            }
        }
        return ans;
    }
};