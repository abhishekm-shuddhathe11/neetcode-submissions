// HashSet ( UNordered_set) Approach   TC = O(N^2) ,  Space : O(min(n, character set size))
 

// #include<bits/stdc++.h>
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.size();
//         unordered_set<char> st;

//         int i=0; 
//         int maxLength = 0;
//         for(int j=0; j<n; j++){
            
//             while( st.find(s[j]) != st.end() ){
//                 st.erase(s[i]);
//                 i++;
//             }
//             st.insert(s[j]);

//             int length = j-i+1;
//             maxLength = max(maxLength , length);
//         }
//         return maxLength;
//     }
// };


// =====================================================================================================//

class Solution{
public:
     int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;

        int i = 0;
        int maxLength = 0;
        for(int j=0; j<n; j++){

            if(mp.count(s[j]) && mp[s[j]]>=i ){
            i = mp[s[j]] + 1;
        }
        mp[s[j]] = j;

        int length = j-i+1 ;
        maxLength = max(maxLength,length);
        }
        return maxLength;
     }
};
