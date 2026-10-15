class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<char>st;

        for(char ch:s){

            if( ( ch == '{' ) || (ch == '(') || (ch == '[' ) ){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if( (top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']') ){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
         if(st.empty()) { return true; }
          return  false;
    }
};
