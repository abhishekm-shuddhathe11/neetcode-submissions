#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        vector<vector<string>> ans;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {

            if (visited[i])      continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < n; j++) {

                if (visited[j])   continue;

                if (strs[i].length() != strs[j].length())
                    continue;

                int freq[26] = {0};

                // Compare character frequencies
                for (int k = 0; k < strs[i].length(); k++) {
                    freq[strs[i][k] - 'a']++;
                    freq[strs[j][k] - 'a']--;
                }

                bool isAnagram = true;

                // Verify all frequencies became zero
                for (int l = 0; l < 26; l++) {
                    if (freq[l] != 0) {
                        isAnagram = false;
                        break;
                    }
                }

                if (isAnagram) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            ans.push_back(group);
        }

        return ans;
    }
};