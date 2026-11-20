
class Solution {
public:

    // Check whether substring s[i...j] is a palindrome
    bool isPalindrome(string &s, int i, int j) {

        while(i < j) {

            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    void solve(int i, string &s,vector<vector<string>> &ans,vector<string> &op) {

        // Base case
        if(i == s.size()) {
            ans.push_back(op);
            return;
        }

        // Explore all possible substrings
        for(int j = i; j < s.size(); j++) {

            if(isPalindrome(s, i, j)) {

                op.push_back(s.substr(i, j-i+1));

                // Explore remaining string
                solve(j+1, s, ans, op); // why j+1 in R.C notes/ChatGpt 

                // Backtrack
                op.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> op;
        solve(0, s, ans, op);
        return ans;
    }
};
