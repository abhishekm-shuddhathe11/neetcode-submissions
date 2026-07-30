// Brutte O(N*N*N) => overall TC = O(N^3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        int maxLength = 1;

        for (int i = 0; i < n; i++) {

            int current = nums[i];
            int length = 1;

            while (true) {

                bool found = false;

                // Search the entire array for current + 1
                for (int j = 0; j < n; j++) {

                    if (nums[j] == current + 1) {
                        current++;
                        length++;
                        found = true;
                        break;
                    }
                }

                // Stop if next consecutive number doesn't exist
                if (!found)
                    break;
            }

            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};

//=================================================================================================================//

// Sorting Approach TC = O(N log N)  SC = O(1)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {

//         int n = nums.size();

//         if (n == 0)
//             return 0;

//         sort(nums.begin(), nums.end());

//         int length = 1;
//         int maxLength = 1;

//         for (int i = 1; i < n; i++) {

//             // Consecutive number
//             if (nums[i] == nums[i - 1] + 1) {
//                 length++;
//             }

//             // Duplicate number
//             else if (nums[i] == nums[i - 1]) {
//                 continue;
//             }

//             // Sequence breaks
//             else {
//                 length = 1;
//             }

//             maxLength = max(maxLength, length);
//         }

//         return maxLength;
//     }
// };