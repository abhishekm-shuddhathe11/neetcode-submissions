//  => Time Complexity :  O(|s| + |t|)  Space Complexity : O(1)

#include<bits/stdc++.h>
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();

        if(m==0 || m>n){
            return "";
        }

        int freq1[128] = {0};
    
        for(int i=0; i<m; i++){
            freq1[t[i]]++;
        }
        
        int required = 0;
        for(int i =0; i<128; i++){
            if(freq1[i]!=0){
            required++;
            }
        }

        string bestAns = "";
        int bestlen = INT_MAX, bleft =0;

        int windowFreq[128] = {0};
        int formed =0;

        int left = 0;
        for( int right=0; right < n; right++ ){
            
            windowFreq[s[right]]++;

            if( windowFreq[s[right]] == freq1[s[right]] ) {
                formed++;
            }

            if(formed == required ){   // If you only used if, you'd stop after removing one character and potentially miss further shrinking. Thats why we required Below WHILE to Find possible Smallest/ minimum Window Substring

                while(formed == required ){    // "As long as the window is still valid, keep trying to make it smaller."
                    // If current window is valid
                    int currentLen = right -left+1;

                    if(currentLen < bestlen){
                        bestlen = currentLen;
                        bleft = left;
                    }

                    char ch = s[left];
                    windowFreq[ch]--;

                    if( windowFreq[ch ] < freq1[ch] ){
                        formed--;
                    }
                    left++;
                }
            }   
        }
        if(bestlen != INT_MAX ){
            return s.substr(bleft ,bestlen);
        }
       return "";
    }
};

// ChatGPT
 
 //=> Time Complexity :  O(|s| + |t|)  Space Complexity : O(1) (USES UNSIGND CHAR)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     string minWindow(string s, string t) {

//         int n = s.size();
//         int m = t.size();

//         if (m == 0 || n < m) {
//             return "";
//         }

//         // 1. Frequency required from t
//         int freq1[128] = {0};

//         for (int i = 0; i < m; i++) {
//             freq1[(unsigned char)t[i]]++;
//         }

//         // 2. Number of distinct characters required
//         int required = 0;

//         for (int i = 0; i < 128; i++) {
//             if (freq1[i] != 0) {
//                 required++;
//             }
//         }

//         // 3. Best answer
//         string bestAns = "";
//         int bestlen = INT_MAX , bestLeft = 0;

//         // 4. Current window frequency
//         int windowFreq[128] = {0};

//         int formed = 0;
//         int left = 0;

//         // 5. Expand window using right
//         for (int right = 0; right < n; right++) {

//             // Add s[right] to current window
//             windowFreq[(unsigned char)s[right]]++;

//             int currentFreq = windowFreq[(unsigned char)s[right]];
//             int requiredFreq = freq1[(unsigned char)s[right]];

//             // Character requirement has just become satisfied
//             if (currentFreq == requiredFreq) {
//                 formed++;
//             }

//             // 6. Current window is valid
//             if (formed == required) {

//                 // 7. Shrink from left while window remains valid
//                 while (formed == required) {

//                     int currentLen = right - left + 1;

//                     // Found a smaller valid window
//                     if (currentLen < bestlen) {
//                         bestlen = currentLen;
//                         bestLeft = left;
//                     }

//                     // Character leaving the window
//                     unsigned char ch = s[left];

//                     windowFreq[ch]--;

//                     // Removing ch broke its requirement
//                     if (windowFreq[ch] < freq1[ch]) {
//                         formed--;
//                     }

//                     left++;
//                 }
//             }
//         }

//         // 8. No valid window found
//         if (bestlen != INT_MAX) {
//             return s.substr(bestLeft , bestlen);
//         }

//         return "";
//     }
// };
