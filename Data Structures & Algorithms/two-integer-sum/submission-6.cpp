// Optimal

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      unordered_map<int,int> mp;

      for(int i=0; i<nums.size(); i++){
        int need = target - nums[i];

        if(mp.count(need)){
            return {mp[need], i};
        }
        mp[nums[i]] = i;
      }
      return {};
    }
};

//=======================================================


// Better 
// But this question to ask to return original index sum whose sum is equal to target
// TC = O(N logN)     SC = O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         sort(nums.begin() , nums.end());
//         int left = 0, right=nums.size()-1;

//         while(left<right){
//             int sum = nums[left]+nums[right];
//             if(sum==target)
//                 return {left,right};

//             else if(sum<target)
//                 left++;

//             else
//                 right--;
//         }
//         return {};
//     }
// };

//===========================================


// Brutte 
      //  TC = O(N^2)
      //  SC = O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]+ nums[j] == target)
//                 return {i,j};
//             }
//         }
//         return {};
//     }
// };
