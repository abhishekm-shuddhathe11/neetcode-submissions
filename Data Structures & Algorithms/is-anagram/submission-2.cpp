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

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>mp;
        if(s.length() != t.length() ){
            return false;
        }

        for(auto x:s)
            mp[x]++;
        
        for (auto x:t)
            mp[x]--;
        

         for (auto x : mp)
        {
            if (x.second != 0)
                return false;
        }

        return true;

    }
};