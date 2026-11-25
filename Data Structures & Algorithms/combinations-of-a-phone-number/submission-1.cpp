// Complexity	Analysis
// Time	            : O(n* 4^n)
// Auxiliary space	: O(n)
// Output space	    : O(n * 4^n)


class Solution {
public:

    void solve(int i, const string& digits, string& op, vector<string>&ans, const vector<string>& mapping){

        if( i >= digits.length() ){
            ans.push_back(op);
            return;
        }
 
        int index = digits[i] - '0';

        for(int j=0; j< mapping[index].length(); j++){

            op.push_back(mapping[index][j]);
            solve(i+1, digits, op, ans, mapping );
            op.pop_back();
        }  
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0)
        {
            return {};
        }
        vector<string>ans;
        string output = "";
        vector<string>mapping = {"", "", "abc","def","ghi","jkl", "mno","pqrs","tuv", "wxyz"};
        solve(0, digits, output, ans, mapping);
        return ans;
    }
};