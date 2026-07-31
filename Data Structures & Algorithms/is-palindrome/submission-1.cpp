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


//======================================================================//

class Solution{
public:
bool isPalindrome(string s) {
    int l=0,r=s.size()-1;

    while(l<r) {
        if(!isalnum(s[l])) l++;
        else if(!isalnum(s[r])) r--;
        else if(tolower(s[l])!=tolower(s[r]))
            return false;
        else {
            l++;
            r--;
        }
    }
    return true;
}
};