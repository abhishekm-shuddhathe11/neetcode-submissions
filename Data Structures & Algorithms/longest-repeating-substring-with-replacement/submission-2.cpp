// Brutte Force Soluton : TC = O(N^2)  SC = O(1)

// class Solution {
// public:
//     int characterReplacement(string s, int k) {

//         int n = s.size();
//         int maxLen = 0;

//         for (int i = 0; i < n; i++) {

//             int freq[26] = {0};
//             int maxFreq = 0;

//             for (int j = i; j < n; j++) {

//                 // Add current character
//                 freq[s[j] - 'A']++;

//                 // Update maximum frequency
//                 maxFreq = max(maxFreq, freq[s[j] - 'A']);

//                 // Current window length
//                 int currLen = j - i + 1;

//                 // Characters that need replacement
//                 int replacements = currLen - maxFreq;

//                 // Check validity
//                 if (replacements <= k) {
//                     maxLen = max(maxLen, currLen);
//                 }
//             }
//         }

//         return maxLen;
//     }
// };

// ====================================================================//


// Optimal Approach 
// TC = O(N)   SC = O(1)

#include<bits/stdc++.h>
class Solution{
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        int left = 0;
        int maxLen = 0;
        int freq[26] = {0};
        int maxFreq = 0;
        for(int right=0; right<n; right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq , freq[s[right] - 'A'] );
            // int curr_len = right -left+1;
            // int replacements = curr_len - maxFreq;

            // if current window is Invalid:
            while( ( (right-left+1) ) - maxFreq > k){ 
        // because current length is changing for every invalid case (like incrementing here) , thats why we have to check using current window formula instead of decalring globally , (for both currLen & replacements do the same )
                freq[s[left] - 'A']--;
                left++;
            }
            // valid window case:
            maxLen = max(maxLen , right-left+1);
        }
        return maxLen;
    }
};