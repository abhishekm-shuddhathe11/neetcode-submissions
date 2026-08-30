#include<bits/stdc++.h>
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();

        if(m==0 || m>n){
            return "";
        }

        int freq1[128] = {0};
    
        for(int i=0; i<m; i++){
            freq1[t[i] - 'A']++;
        }
        
        int required = 0;
        for(int i =0; i<128; i++){
            if(freq1[i]!=0){
            required++;
            }
        }

        string bestAns = "";
        int bestlen = INT_MAX, bestRight = 0, bestLeft = 0;

        int windowFreq[128] = {0};
        int formed =0;

        int left = 0;

        for( int right=0; right < n; right++ ){
            
            windowFreq[s[right]- 'A']++;

            if( windowFreq[s[right] - 'A'] == freq1[s[right] -'A'] ) {
                formed++;
            }

            if(formed == required ){   

                while(formed == required ){
                    // If current window is valid
                    int currentLen = right -left+1;

                    if(currentLen < bestlen){
                        bestlen = currentLen;
                        bestLeft = left;
                        bestRight = right ;
                        bestAns = s.substr(left , right-left+1);
                    }

                    char ch = s[left];
                    windowFreq[ch - 'A']--;

                    if( windowFreq[ch - 'A'] < freq1[ch -'A'] ){
                        formed--;
                        left++;
                        break;
                    }
                    else{
                        left++;
                        continue;
                    }
                }
            }   
        }
          if(bestlen != INT_MAX ){
                return bestAns;
            }
            return "";
    }
};
