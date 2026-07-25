#include <vector>
class Solution{
    public:
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n= nums.size();
    vector<int>ans;

    for(int i=0; i<n; i++){

    int prod = 1;

        for(int j=0;j<n;j++){
            if(i!=j){
                prod *= nums[j];
            }
        }
            ans.push_back(prod);
    }
    return ans;
}
};