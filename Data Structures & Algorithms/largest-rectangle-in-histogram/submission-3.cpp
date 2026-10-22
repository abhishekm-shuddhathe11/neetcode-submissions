// Brutte 
//    Time complexity: O(N^2)
//    Auxiliary space:  O(1))

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;

//         for (int i = 0; i < n; i++) {
//             int minHeight = heights[i];

//             for (int j = i; j < n; j++) {
//                 minHeight = min(minHeight, heights[j]);

//                 int width = j - i + 1;
//                 int area = minHeight * width;

//                 maxArea = max(maxArea, area);
//             }
//         }

//         return maxArea;
//     }
// };

//=================================================================================

// Optimal SOlution using Stack

// Time Complexity (TC):  O(N)
// Space Complexity (SC): O(N)

class Solution {
public:
    vector<int> getPreviousSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> getNextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse = getPreviousSmaller(heights);
        vector<int> nse = getNextSmaller(heights);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nse[i] - pse[i] - 1; // "-1" converts the distance between the boundary indices into the actual number of bars inside them

            int area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
