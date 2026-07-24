#include <vector>
class Solution{
    public:
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> answer(n, 1);

    for (int i = 0; i < n; ++i) {
        int currentProduct = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j) { // Skip the current element
                currentProduct *= nums[j];
            }
        }
        answer[i] = currentProduct;
    }

    return answer;
}
};