// class SOlution{
// public:
//     int lengthOfLongestSubstring(string s){
//         int n= s.size();
//         int maxLen = 0;

//         for(int i=0; i<n-1; i++){
//             for(int j=0; j<n; j++){
//                  unordered_set<char>st;

//                 for(int k=i; j>i && k<j; k++){

//                     if(st.count(s[j])){
//                         break;
//                     }
//                     st.insert(s[j]);

//                     int len = j-i+1;
//                     maxLen = max(maxLen , len);
//                 }
//             }
//         }
//         return maxLen;
//     }
// };


//==========================================================================================================//

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
//TC = O(N)  SC = O(N)

// class Solution{
// public:
//      int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         unordered_map<char,int>mp;

//         int i = 0;
//         int maxLength = 0;
//         for(int j=0; j<n; j++){

//             if(mp.count(s[j]) && mp[s[j]]>=i ){
//             i = mp[s[j]] + 1;
//         }
//         mp[s[j]] = j;

//         int length = j-i+1 ;
//         maxLength = max(maxLength,length);
//         }
//         return maxLength;
//      }
// };

//======================================================================================================

//The Most Optimal

//TC = O(n)  SC  = O(1)


class Solution{
public:
     int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int lastseen[128] = {0};
        fill(lastseen , lastseen+128 , -1);

        int i = 0;
        int maxLength = 0;
        for(int j=0; j<n; j++){

            if( lastseen[s[j]] >= i ){
            i = lastseen[s[j]] + 1;
        }
        lastseen[s[j]] = j;

        int length = j-i+1 ;
        maxLength = max(maxLength,length);
        }
        return maxLength;
     }
};