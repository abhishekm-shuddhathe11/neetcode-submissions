// BRUTTE 
     // TC = N × N × (K + 26)  =>  O(N² × K)
     // Auxiliary SC = O(N)   ==> N → Number of strings/elements.     ==>  K → Length of each string.
// If an interviewer explicitly asks for total space including the returned answer, then the answer container stores all input strings, so it's still proportional to the input size (not O(N²)).

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         int n = strs.size();

//         vector<vector<string>> ans;
//         vector<bool> visited(n, false);

//         for (int i = 0; i < n; i++) {

//             if (visited[i])      continue;

//             vector<string> group;
//             group.push_back(strs[i]);
//             visited[i] = true;

//             for (int j = i + 1; j < n; j++) {

//                 if (visited[j])   continue;

//                 if (strs[i].length() != strs[j].length())
//                     continue;

//                 int freq[26] = {0};

//                 // Compare character frequencies
//                 for (int k = 0; k < strs[i].length(); k++) {
//                     freq[strs[i][k] - 'a']++;
//                     freq[strs[j][k] - 'a']--;
//                 }

//                 bool isAnagram = true;

//                 // Verify all frequencies became zero
//                 for (int l = 0; l < 26; l++) {
//                     if (freq[l] != 0) {
//                         isAnagram = false;
//                         break;
//                     }
//                 }

//                 if (isAnagram) {
//                     group.push_back(strs[j]);
//                     visited[j] = true;
//                 }
//             }

//             ans.push_back(group);
//         }

//         return ans;
//     }
// };

// =================================================================================//

// Optimal

// TC = O(N × K log K)    SC = O(N × K)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         unordered_map<string, vector<string>> mp;

//         // Group words by their sorted form
//         for (int i = 0; i < strs.size(); i++) {

//             string key = strs[i];
//             sort(key.begin(), key.end());
//             mp[key].push_back(strs[i]);
//         }

//         // Store all groups into the answer
//         vector<vector<string>> ans;

//         for (auto &entry : mp) {
//             ans.push_back(entry.second);
//         }

//         return ans;
//     }
// };

// ==================================================================================== //



// Most Optimal
//  TC = 
//  SC = 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            int freq[26] = {0};
            for(int j=0;j<strs[i].size(); j++){
                freq[strs[i][j]-'a']++;
            }
            string key = "";
           for(auto & count:freq){
            key += to_string(count)+"#";
           }
           mp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto &[key, s_anagram] : mp) {
            ans.push_back(move(s_anagram) );
        }

        return ans;
    }
};


