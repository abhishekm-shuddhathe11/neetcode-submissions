class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();
        int maxArea = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int area = min(heights[i], heights[j] ) * (j-i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
