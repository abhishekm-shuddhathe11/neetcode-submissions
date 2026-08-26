// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {

//         int n = s1.size();
//         int m = s2.size();

//         if (n > m) {
//             return false;
//         }

//         int freq1[26] = {0};
//         int freq2[26] = {0};

//         // Frequency of s1
//         for (int i = 0; i < n; i++) {
//             freq1[s1[i] - 'a']++;
//         }

//         // Build first window of size n
//         for (int i = 0; i < n; i++) {
//             freq2[s2[i] - 'a']++;
//         }

//         // Check first window
//         if (equal(begin(freq1), end(freq1), begin(freq2))) {
//             return true;
//         }

//         int left = 0;

//         // Slide window by 1
//         for (int right = n; right < m; right++) {

//             // Remove character leaving the window
//             freq2[s2[left] - 'a']--;

//             // Add character entering the window
//             freq2[s2[right] - 'a']++;

//             left++;

//             // Compare frequencies
//             if (equal(begin(freq1), end(freq1), begin(freq2))) {
//                 return true;
//             }

//         }

//         return false;
//     }
// };

//=============================================================================//

// Instead of using freq [26] , we can use => arr<int,26> freq {}  for ease Comparission

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool SameFrequency(array<int,26> freq1, array<int,26> freq2 ){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        array<int,26> freq1{};
        array<int,26> freq2{};

        if (n > m) {
            return false;
        }

        for(int i=0; i<n; i++){
            freq1[s1[i]-'a']++;
        }

        for(int j=0; j<n; j++){
            freq2[s2[j] - 'a']++;
        }
        if( SameFrequency(freq1 , freq2) ){
                return true;
            }

        int left = 0;
        for(int right = n; right<m; right++){

            freq2[s2[left] - 'a']--;

            freq2[s2[right] - 'a']++;

            if( SameFrequency(freq1 , freq2) ){
                return true;
            }
            left++;
        }

        return false;
    }
};