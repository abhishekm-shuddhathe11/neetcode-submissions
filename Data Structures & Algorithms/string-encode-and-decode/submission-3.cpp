// TC = SC = O(N)

class Solution {
public:
    
    string encode(vector<string>& strs) {
        string ans = "";

        for (const auto& s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }

        return ans;
    }

    vector<string> decode(string s){
    vector<string> ans;
    int i = 0;
    while(i < s.size()) {
        int j = i;
        while(s[j] != '#'){
            j++;
        }
        int length = std::stoi(s.substr(i, j - i));
        i = j + 1;
        string word = s.substr(i, length);
        ans.push_back(word);
        i+=length;
    }
    return ans;
}
};
