// Iterative BS

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
        
//         int s = 0 , e = nums.size()-1 ;

//         while(s<=e){
//             int mid = s + (e-s)/2 ;

//             if(nums[mid] == target ) {
//                 return mid;
//             }
//             else if(nums[mid] < target) {
//                 s = mid + 1;
//             }
//             else {
//                 e = mid -1;
//             }
//         }
//         return -1;
//     }
// };

// ===================================================

// Recursive BS

// class Solution {
// public:
//     int binarySearch(vector<int>& nums, int s, int e, int target) {

//         if (s > e) {
//             return -1;
//         }

//         int mid = s + (e - s) / 2;

//         if (nums[mid] == target) {
//             return mid;
//         }
//         else if (nums[mid] < target) {
//             return binarySearch(nums, mid + 1, e, target);
//         }
//         else {
//             return binarySearch(nums, s, mid - 1, target);
//         }
//     }

//     int search(vector<int>& nums, int target) {
//         return binarySearch(nums, 0, nums.size() - 1, target);
//     }
// };

// =======================================================

class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {

        int s = 0;
        int e = nums.size();

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return -1;
    }
};

