

    class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";

        for (const auto& s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            // Find '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Extract length
            int length = stoi(s.substr(i, j - i));

            // Move to first character of the word
            i = j + 1;

            // Extract the word
            string word = s.substr(i, length);

            ans.push_back(word);

            // Move to next encoded string
            i += length;
        }

        return ans;
    }
};
