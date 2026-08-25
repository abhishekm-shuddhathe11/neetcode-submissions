// TC = O(N * logn)    SC = O(N)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         unordered_map<int, int> mp;

//         for (auto n : nums) {
//             mp[n]++;
//         }

//         vector<pair<int, int>> arr;

//         for (auto &p : mp) {
//             arr.push_back({p.first, p.second});
//         }

//         sort(arr.begin(), arr.end(),
//              [](const pair<int,int>& a, const pair<int,int>& b) {
//                  return a.second > b.second;
//              });

//         vector<int> result;

//         for (int i = 0; i < k && i < arr.size(); i++) {
//             result.push_back(arr[i].first);
//         }

//         return result;
//     }
// };

//==============================//

// for below both MinHeap approaches  ==>   TC = O(N logK)    SC = O(N)

// Code (With Custom Comparator)
//class Solution {
// public:

//     struct CustomComparator {
//         bool operator() (pair<int,int>&a, pair<int, int>&b){
//             return a.second>b.second;
//         }
//     };

//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         // Step 1: Count frequencies
//         unordered_map<int, int> freqMap;
//         for (int n : nums) {
//             freqMap[n]++;
//         }

//         // Step 2: Min Heap
//         using pii = pair<int,int>;
//         priority_queue< pii ,vector<pii>, CustomComparator> minHeap;

//         // Step 3: Keep only top k elements
//         for (auto &[element, frequency] : freqMap) {

//             minHeap.push({element, frequency});

//             if (minHeap.size() > k) {
//                 minHeap.pop();
//             }
//         }

//         // Step 4: Extract answer
//         vector<int> ans;
//         while (!minHeap.empty()) {
//             ans.push_back(minHeap.top().first);
//             minHeap.pop();
//         }
//         return ans;
//     }
// };


// Code (Without Custom Comparator)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> freqMap;

        for (int n : nums) {
            freqMap[n]++;
        }

        // Step 2: Min Heap
        // Stores: (frequency, element)
        using pii = pair<int,int>;
        priority_queue< pii,vector<pii>,greater<pii>> minHeap;

        // Step 3: Keep only top k elements
        for (auto &[element, frequency] : freqMap) {

            minHeap.push({frequency, element});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 4: Extract answer
        vector<int> ans;

        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

//==============================//

// OPtimal Approach      TC= O(N)  SC = O(N)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         // Step 1: Count frequency of each element
//         unordered_map<int, int> freqMap;

//         for (int n : nums) {
//             freqMap[n]++;
//         }

//         // Step 2: Create buckets // Index = Frequency   // Value = List of elements having that frequency
//         vector<vector<int>> buckets(nums.size() + 1); //weTook 2D arr because multiple elements can have same frequency

//         for (auto &[element, frequency] : freqMap) {
//             buckets[frequency].push_back(element);
//         }

//         // Step 3: Traverse buckets from highest frequency to lowest
//         vector<int> ans;

//         for (int freq = buckets.size() - 1; freq >= 1; freq--) {

//             for (int element : buckets[freq]) {

//                 ans.push_back(element);

//                 // Stop once we have k elements
//                 if (ans.size() == k) {
//                     return ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };


// => the optimal Solution it contains Nested Loops  ==> "Why isn't this O(n²)?"   ===>  A concise answer is:
 // ans=> "Although there are nested loops, the inner loop doesn't iterate n times for each outer iteration.-
 // Each element is placed into exactly one bucket based on its frequency, 
 //so across all buckets, every element is processed only once.The outer loop scans the bucket indices (O(n)), 
 //and the total work done by all inner loops combined is also O(n),  giving an overall time complexity of O(n)."


