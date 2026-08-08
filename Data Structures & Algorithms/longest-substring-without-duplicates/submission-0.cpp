#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> st;

        int i=0; 
        int maxLength = 0;
        for(int j=0; j<n; j++){
            
            while( st.count(s[j]) ){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);

            int length = j-i+1;
            maxLength = max(maxLength , length);
        }
        return maxLength;
    }
};
