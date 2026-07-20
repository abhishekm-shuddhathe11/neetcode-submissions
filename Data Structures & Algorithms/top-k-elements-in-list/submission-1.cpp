#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies
        std::unordered_map<int, int> frequency_map;
        for (int num : nums) {
            frequency_map[num]++;
        }
        
        // Step 2: Copy pairs to a vector for sorting
        std::vector<std::pair<int, int>> freq_vec(frequency_map.begin(), frequency_map.end());
        
        // Step 3: Sort in descending order based on frequency
        std::sort(freq_vec.begin(), freq_vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        });
        
        // Step 4: Collect the top k elements
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freq_vec[i].first);
        }
        
        return result;
    }
};