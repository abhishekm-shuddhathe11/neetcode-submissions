//Brutte Solution
   // TC = O(N logN)    
   // SC = O(1) => (If sorting is considered in-place; otherwise it depends on the sort implementation.)

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         if(s.length() != t.length() ){
//             return false;
//         }

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;
//     }
// };

// ==============================================================================================================

//  TC =O(n)
// SC = (k) where k is the number of distinct characters (at most 26 for lowercase English letters).

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         unordered_map<char,int>mp;
//         if(s.length() != t.length() ){
//             return false;
//         }

//         for(auto x:s)
//             mp[x]++;
        
//         for (auto x:t)
//             mp[x]--;
        

//          for (auto x : mp)
//         {
//             if (x.second != 0)
//                 return false;
//         }

//         return true;

//     }
// };

// ================================================

class Solution {
public:
    bool isAnagram(string s, string t){

        if(s.length() != t.length()){
            return false;
        }
        int freq[26] = {0};

        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(int i=0; i<26; i++){
            if(freq[i]!= 0 ){
                return false;
            }
        }
        return true;
    }
};