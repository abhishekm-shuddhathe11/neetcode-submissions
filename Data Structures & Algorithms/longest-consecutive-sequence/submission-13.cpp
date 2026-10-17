// Brutte O(N*N*N) => overall TC = O(N^3)

// #include<bits/stdc++.h>
// using namespace std;

// class Solution{
// public:
//     int longestConsecutive(vector<int>& nums){
//         int n = nums.size();
//         int maxLen = 1;
//         if (n==0) return 0;
//         for(int i=0; i<n; i++){

//             int current = nums[i];
//             int length = 1;

//             while(true){
//             bool found= false;
//             for(int j=0; j<n; j++){
//                 if(nums[j] == current +1){
//                     length++;
//                     current++;
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found) break;
//             }
//             maxLen = max(maxLen , length);
//         }
//         return maxLen;
//     }
// };

//=================================================================================================================//

// Sorting Approach TC = O(N log N)  SC = O(1)

// #include<bits/stdc++.h>

// class Solution{
// public:
//     int longestConsecutive(vector<int>& nums){

//         int n = nums.size();
//         if(n ==0) { return 0;}

//         int maxLen = 1;
//         int length = 1;

//         sort(nums.begin(), nums.end());

//         for(int i=1; i<n; i++){

//             if(nums[i] == nums[i-1]+1){
//                 length++;
//             }
//             else if(nums[i] == nums[i-1]){
//                 continue;
//             }
//             else{
//                 length =1;
//             }
//             maxLen = max(maxLen , length);
//         }
//         return maxLen;
//     }
// };

// =========================================================================================//

//  The Optimal Solution using Set

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){

        int n = nums.size();
        if(n ==0) { return 0;}

        int maxLen = 1;
        int length = 1;
        unordered_set<int>st(nums.begin(), nums.end());

        for( int curr: st){

            if(st.count(curr + 1)){
                length++;
                curr--;            }
            if(st.count(curr-1)){
                continue;
            }
            maxLen = max(maxLen , length);
        }
        return maxLen;
    }
};
