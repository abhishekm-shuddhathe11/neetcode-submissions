#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<string> arr = tokens;
        int n = arr.size();

        while( arr.size() > 1){
        
         int opIdx = 0;

            for(int i=0; i<arr.size(); i++){
                if(arr[i] == "+" || arr[i] == "-" ||arr[i] == "*" ||arr[i] == "/" ){
                    opIdx = i; 
                    break;
                }
            }

            int num1 = std::stoi(arr[opIdx - 1]);
            int num2 = std::stoi(arr[opIdx -2]);
            int res = 0;

            if(arr[opIdx] == "+"){
                res = num1 + num2; 
            }
            
            else if(arr[opIdx] == "-"){
                res = num2 - num1; 
            }
            
            else if(arr[opIdx] == "*"){
                res = num1 * num2; 
            }
            
            else if(arr[opIdx] == "/"){
                res = num2 / num1; 
            }
            
            // Remove num1 , num2 & operator (thats y we erase it from -2 to +1)
            arr.erase(arr.begin()+opIdx-2, arr.begin()+ opIdx+1);


            // Add the Current result to the which we processed through the last operator which we found 
            arr.insert(arr.begin() +opIdx-2, to_string(res));

        }
        return stoi(arr[0]);
    }
};