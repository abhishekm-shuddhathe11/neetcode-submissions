// Interview takeaway: When binary search finds the first valid answer, and you maintain the boundaries as you have here, low == high at termination. That converged value is the answer. 

// TC = O(nlog M)
// SC = O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        // int ans = INT_MAX;
        int low = 1;
        int high = *max_element( piles.begin(), piles.end() );

        while(low < high){
            int mid = low + (high - low)/2 ;

            int hours = 0;

            for(int i=0; i<n; i++){
                
                int time =  (piles[i] + mid-1) / mid;
                // int possibleAns = 0;
                hours += time;
            }

                if(hours > h){
                    low  = mid+1;
                }
                else{
                    // possibleAns = mid;
                    high = mid;
                }
                // ans = min (ans ,possibleAns );
        }
        return low;
    }
};
