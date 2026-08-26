// Brutte For(i){ for(j) }  & then apply formula

// class Solution {
// public:
//     int trap(vector<int>& height) {

//         int totalWater = 0;
//         int n = height.size();

//         for(int i=0; i<n; i++){    // i->n   ( 0 ->  <=i)  && ( =i -> n)
 
//             int LeftMax = 0, RightMax = 0;

//             for(int j =0; j<=i; j++){
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



// Using Prefix max & Suffix Max arrays & using them in one final for loop

class Solution {

    vector<int> prefixMax(vector<int>& height){

        vector<int> ans(height.size() +1);
        int leftMax = 0;

        for(int i=0; i<height.size(); i++){
            leftMax = max(leftMax , height[i]);

            ans[i] = leftMax;
        }
        return ans;
    }

    vector<int> suffixMax(vector<int>& height){

        vector<int> ans(height.size() +1);
        int rightMax = 0;

        for(int i= height.size()-1; i>=0; i--){
            rightMax = max(rightMax , height[i]);

            ans[i] = rightMax;
        }
        return ans;
    }

public:
    int trap(vector<int>& height) {

        int totalWater = 0;
        int n = height.size();

        vector<int> prefix = prefixMax(height);
        vector<int> suffix = suffixMax(height);

        for(int i=0; i<n; i++){   

            totalWater += min( prefix[i], suffix[i] ) - height[i];     
        }         
        return totalWater;
    }
};


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
