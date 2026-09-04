// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {

//         vector<string> arr = tokens;

//         while(arr.size() > 1) {

//             int opIdx = -1;

//             // Find FIRST operator
//             for(int i = 0; i < arr.size(); i++) {

//                 if(arr[i] == "+" || arr[i] == "-" ||
//                    arr[i] == "*" || arr[i] == "/") {

//                     opIdx = i;
//                     break;
//                 }
//             }

//             int num1 = stoi(arr[opIdx - 2]); // left operand
//             int num2 = stoi(arr[opIdx - 1]); // right operand

//             int res = 0;

//             if(arr[opIdx] == "+") {
//                 res = num1 + num2;
//             }
//             else if(arr[opIdx] == "-") {
//                 res = num1 - num2;
//             }
//             else if(arr[opIdx] == "*") {
//                 res = num1 * num2;
//             }
//             else if(arr[opIdx] == "/") {
//                 res = num1 / num2;
//             }

//             // Remove: operand1, operand2, operator
//             arr.erase(arr.begin() + opIdx - 2,
//                       arr.begin() + opIdx + 1);

//             // Insert result
//             arr.insert(arr.begin() + opIdx - 2,
//                        to_string(res));
//         }

//         return stoi(arr[0]);
//     }
// };


// ======================================================================================

// The Optimal Approach 


class Solution{
public:
    int evalRPN(vector<string> & tokens){

        stack<string> st;

        for(int i=0; i<tokens.size(); i++){

            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){

                int num1 = stoi(st.top()); st.pop();
                int num2 = stoi(st.top()); st.pop();
                int res = 0;

                if(tokens[i] == "+"){
                    res = num2 + num1;
                }
                
                else if(tokens[i] == "-"){
                    res = num2 - num1;
                }
                
                else if(tokens[i] == "*"){
                    res = num2 * num1;
                }
                
                else if(tokens[i] == "/"){
                    res = num2 / num1;
                }
                st.push( to_string(res) );
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi( st.top() );

    }
};

