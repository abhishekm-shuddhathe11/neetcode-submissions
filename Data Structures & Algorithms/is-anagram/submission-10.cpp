

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

//======================================================================================================
                     // Better Solution 
//  TC =O(n)
// SC = (k) where k is the number of distinct characters (at most 26 for lowercase English letters).
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>mp;
        if(s.length() != t.length() ){
            return false;
        }

        for(auto x:s){
            mp[x]++;
        }
        for (auto ch:t){
            mp[ch]--;
        }
        for (auto &p : mp)
        {
            if (p.second != 0)
                return false;
        }
        //  for (auto &[ch, count] : mp)
        // {
        //     if (count != 0)
        //         return false;
        // }
        return true;

    }
};

//========================================================================

// Optimal Solutions:
// TC = O(N)
// SC = O(1)   (Fastest for lowercase English letters (a–z))

// class Solution {
//     public:
//      bool isAnagram(string s, string t) {

//          if(s.length() != t.length() ){
//              return false;
//          }

//          int arr[26] = {0};

//          for(char ch:s)
//             arr[ch-'a']++;

//         for(auto ch:t)
//             arr[ch-'a']--;

//         for(int n:arr){
//             if(n!=0){
//                 return false;
//             }
//         }
//         return true;
//      }
// };