// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {

//         int n = temperatures.size();
//         vector<int> result(n, 0);

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(temperatures[j] > temperatures[i]) {
//                     result[i] = j-i;
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

// =========================================================================================================//

// The Optimal Stack Solution 
// TC = O(N)   => each index is pushed once and popped at most once.
// SC  = O(N)  => Stack + Result

class Solution{
public:

    vector<int> dailyTemperatures(vector<int> & temperatures){

        int n = temperatures.size();
        vector<int>result(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while( !st.empty() && temperatures[i] > temperatures[st.top()] ){ // The reason we use "while" instead of "if" in Daily Temperatures is that one hotter temperature can resolve multiple previous unresolved days, not just one.
                result[ st.top() ] = i - st.top();
                st.pop();
            }
        st.push(i);  // And the stack contains indices of unresolved days.
        }
        return result;
    }
};

// Rule := Use while in a monotonic-stack problem when processing the current element may resolve multiple previous elements. Use if only when you need to handle at most one element per iteration.  




