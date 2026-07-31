#include<bits/stdc++.h>
#include<cctype>
class Solution {
public:
    bool ispalindrome(string s){

        int i=0, j=s.size()-1;

        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            else
                i++;
                j--;
        }
        return true;
    }

    bool isPalindrome(string s) {

        int n= s.size();
        string t = "";

        for(int i=0; i<n; i++){
            if( isalnum(s[i]) ){
                t+=tolower(s[i]);
            }
        }
        return ispalindrome(t);
    }
};
