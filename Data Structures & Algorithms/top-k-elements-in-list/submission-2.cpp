class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (auto n : nums) {
            mp[n]++;
        }

        vector<pair<int, int>> arr;

        for (auto &p : mp) {
            arr.push_back({p.first, p.second});
        }

        sort(arr.begin(), arr.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second > b.second;
             });

        vector<int> result;

        for (int i = 0; i < k && i < arr.size(); i++) {
            result.push_back(arr[i].first);
        }

        return result;
    }
};