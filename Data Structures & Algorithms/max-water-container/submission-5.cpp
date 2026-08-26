// Brutte Approach  TC = O(N^2)  SC = O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int largeArea = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                //Instead of this:
                // int length = min(height[i] , height[j]);
                // int breadth = j-i;
                // int area =  length * breadth;

                // Use this:
                int area = min(height[i], height[j]) * (j - i);

                largeArea = max(area, largeArea);
            }
        }
        return largeArea;
    }
};

// =========================================================================================================//

// Optimal 2-pointer:

// class Solution{
// public:
// int maxArea(vector<int>& height){
//     int s=0 , e=height.size()-1;
    
//     int LargeArea = 0;

//     while(s<e){

//         int area = min(height[s],height[e]) * (e-s);  
//         LargeArea = max(area, LargeArea);

//             if( height[s] <= height[e] ){
//                 s++;
//             }
//             else
//                 e--;

//       }
//       return LargeArea;
//     }
// };