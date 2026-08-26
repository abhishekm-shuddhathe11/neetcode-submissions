// Brutte For(i){ for(j) }  & then apply formula
// class Solution {
// public:
//     int trap(vector<int>& height) {

//         int totalWater = 0;
//         int n = height.size();

//         for(int i=0; i<n; i++){

//             int LeftMax = 0, RightMax = 0;

//             for(int j =0; j<= i; j++){
//                 LeftMax = max(LeftMax , height[j]);
//             }

//             for(int j=i; j<n; j++){
//                 RightMax = max(RightMax , height[j]);
//             }
//                 totalWater += min( LeftMax, RightMax ) - height[i];
            
//         }
         
//         return totalWater;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {

        int totalWater = 0;
        int n = height.size();

        for(int i = 0; i < n; i++) {

            int LeftMax = 0;
            int RightMax = 0;

            // Find maximum wall on left
            for(int j = 0; j <= i; j++) {
                LeftMax = max(LeftMax, height[j]);
            }

            // Find maximum wall on right
            for(int j = i; j < n; j++) {
                RightMax = max(RightMax, height[j]);
            }

            // Water trapped at index i
            totalWater += min(LeftMax, RightMax) - height[i];
        }

        return totalWater;
    }
};


// Using Prefix max & Suffix Max arrays & using them in one final for loop

// Optimal Solution ( TWO - POINTER) TC = O(N)   SC = O(1)

// class Solution {
// public:
//     int trap(vector<int>& height) {

//         int left =0 , right = height.size()-1;
//         int leftMax = 0 , rightMax = 0;
//         int totalWater = 0;

//         while(left < right) {
             
//             if(height[left] < height[right]){
//                 leftMax = max(leftMax, height[left]);
//                 if( height[left]< leftMax){
//                     totalWater += leftMax - height[left];
//                 }
//                 left++;
//             }

//             else{
//                 rightMax = max(rightMax , height[right]); 
//                 if(height[right]< rightMax){
//                     totalWater += rightMax - height[right];
//                 }
//                 right--;
//             }
//         }
//         return totalWater;
//     }
// };
