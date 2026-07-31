// #include<bits/stdc++.h>
// #include<cctype>
// class Solution {
// public:
//     bool ispalindrome(string s){

//         int i=0, j=s.size()-1;

//         while(i<j){
//             if(s[i] != s[j]){
//                 return false;
//             }
//             else
//                 i++;
//                 j--;
//         }
//         return true;
//     }

//     bool isPalindrome(string s) {

//         int n= s.size();
//         string t = "";

//         for(int i=0; i<n; i++){
//             if( isalnum(s[i]) ){
//                 t+=tolower(s[i]);
//             }
//         }
//         return ispalindrome(t);
//     }
// };



// ===============================================================================//

#include<bits/stdc++.h>
class Solution{
public:

bool isPalindrome(string s){
    // int s=0, e= s.size()-1;
    string t = "";
    for(int i=0; i<s.size(); i++){
        if( isalnum(s[i])){
            t+= tolower(s[i]);  // isdigit(s[i]) ? s[i] : tolower(s[i]);works => because: tolower('7') return 7 only,
                                // thats why dont need to check isdigit();
        }
    }
    string c = t;
    reverse(t.begin(), t.end());

    return c == t;
}
};


// =========================================================================== //

// class Solution{
// public:

// bool isPalindrome(string s){


// }
// }

