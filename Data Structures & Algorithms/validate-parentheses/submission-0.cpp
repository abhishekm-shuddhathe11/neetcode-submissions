#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;

        if(s.empty()){
            return true;
        }

        for( auto ch:s){

            if( ch == '('|| ch== '[' || ch== '{'  ){
                st.push(ch);
            }
            else{ 
                if(!st.empty() ){
                    char top = st.top();

                    if( (top == '(' && ch ==')') || (top == '{' && ch =='}') || ( top == '[' && ch ==']') ){
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
       return st.empty() ?  true :  false;
    }
};
