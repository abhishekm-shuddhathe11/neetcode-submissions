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

#include<bits/stdc++.h>

class Solution{
public:
    int longestConsecutive(vector<int>& nums){

        int n = nums.size();
        if(n ==0) { return 0;}

        int maxLen = 1;
        int length = 1;

        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){

            if(nums[i] == nums[i-1]+1){
                length++;
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                length =1;
            }
            maxLen = max(maxLen , length);
        }
        return maxLen;
    }
};

// =========================================================================================//

// // The Optimal Solution using Set
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {

//         int n = nums.size();

//         if (n == 0)
//             return 0;

//         unordered_set<int> st;

//         // Step 1: Insert all numbers into the HashSet
//         for (int num : nums) {
//             st.insert(num);
//         }

//         int maxLength = 1;

//         // Step 2: Traverse each number
//         for (int num : nums) {

//             // If previous number exists, this is not the start
//             if (st.count(num - 1))
//                 continue;

//             // Start counting the sequence
//             int current = num;
//             int length = 1;

//             // Keep extending the sequence
//             while (st.count(current + 1)) {
//                 current++;
//                 length++;
//             }

//             maxLength = max(maxLength, length);
//         }

//         return maxLength;
//     }
// };