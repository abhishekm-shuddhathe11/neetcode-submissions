// #include<bits/stdc++.h>
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.size() , m = t.size();

//         if(m==0 || m>n){
//             return "";
//         }

//         int freq1[128] = {0};
    
//         for(int i=0; i<m; i++){
//             freq1[t[i] - 'A']++;
//         }
        
//         int required = 0;
//         for(int i =0; i<128; i++){
//             if(freq1[i]!=0){
//             required++;
//             }
//         }

//         string bestAns = "";
//         int bestlen = INT_MAX;

//         int windowFreq[128] = {0};
//         int formed =0;

//         int left = 0;

//         for( int right=0; right < n; right++ ){
            
//             windowFreq[s[right]- 'A']++;

//             if( windowFreq[s[right]] == freq1[s[right]] ) {
//                 formed++;
//             }

//             if(formed == required ){   

//                 while(formed == required ){
//                     // If current window is valid
//                     int currentLen = right -left+1;

//                     if(currentLen < bestlen){
//                         bestlen = currentLen;
//                         bestAns = s.substr(left , right-left+1);
//                     }

//                     char ch = s[left];
//                     windowFreq[ch - 'A']--;

//                     if( windowFreq[ch ] < freq1[ch] ){
//                         formed--;
//                         break;
//                     }
//                     left++;
//                 }
//             }   
//         }
//         if(bestlen != INT_MAX ){
//             return bestAns;
//         }
//        return "";
//     }
// };

// ChatGPT


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if (m == 0 || n < m) {
            return "";
        }

        // 1. Frequency required from t
        int freq1[128] = {0};

        for (int i = 0; i < m; i++) {
            freq1[(unsigned char)t[i]]++;
        }

        // 2. Number of distinct characters required
        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (freq1[i] != 0) {
                required++;
            }
        }

        // 3. Best answer
        string bestAns = "";
        int bestlen = INT_MAX;

        // 4. Current window frequency
        int windowFreq[128] = {0};

        int formed = 0;
        int left = 0;

        // 5. Expand window using right
        for (int right = 0; right < n; right++) {

            // Add s[right] to current window
            windowFreq[(unsigned char)s[right]]++;

            int currentFreq = windowFreq[(unsigned char)s[right]];
            int requiredFreq = freq1[(unsigned char)s[right]];

            // Character requirement has just become satisfied
            if (currentFreq == requiredFreq) {
                formed++;
            }

            // 6. Current window is valid
            if (formed == required) {

                // 7. Shrink from left while window remains valid
                while (formed == required) {

                    int currentLen = right - left + 1;

                    // Found a smaller valid window
                    if (currentLen < bestlen) {
                        bestlen = currentLen;
                        bestAns = s.substr(left, currentLen);
                    }

                    // Character leaving the window
                    unsigned char ch = s[left];

                    windowFreq[ch]--;

                    // Removing ch broke its requirement
                    if (windowFreq[ch] < freq1[ch]) {
                        formed--;
                    }

                    left++;
                }
            }
        }

        // 8. No valid window found
        if (bestlen == INT_MAX) {
            return "";
        }

        return bestAns;
    }
};
