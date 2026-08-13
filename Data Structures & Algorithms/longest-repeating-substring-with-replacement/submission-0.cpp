// Brutte Force Soluton : TC = O(N^2)  SC = O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};
            int maxFreq = 0;

            for (int j = i; j < n; j++) {

                // Add current character
                freq[s[j] - 'A']++;

                // Update maximum frequency
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                // Current window length
                int currLen = j - i + 1;

                // Characters that need replacement
                int replacements = currLen - maxFreq;

                // Check validity
                if (replacements <= k) {
                    maxLen = max(maxLen, currLen);
                }
            }
        }

        return maxLen;
    }
};