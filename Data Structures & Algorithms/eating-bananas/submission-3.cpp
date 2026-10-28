// Interview takeaway: When binary search finds the first valid answer, and you maintain the boundaries as you have here, low == high at termination. That converged value is the answer. 

//At that point, the while loop stops.
//Because both variables contain the same value, returning low or high gives the same result.

// while (low < high) means the loop executes only when low is strictly less than high. It does not mean the variables can never become equal.

// TC = O(nlog M)
// SC = O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int low = 1;
        int high = *max_element( piles.begin(), piles.end() );

        while(low < high){
            int mid = low + (high - low)/2 ;

            int hours = 0;

            for(int i=0; i<n; i++){
                int time =  (piles[i] + mid-1) / mid;
                hours += time;
            }

            if(hours > h){
                low  = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;  // return high; both are same 
    }
};
