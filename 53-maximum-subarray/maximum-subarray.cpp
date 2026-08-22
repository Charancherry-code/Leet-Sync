class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int cursum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            
            cursum +=  nums[i];
           maxSum = max(cursum, maxSum );

            if( cursum<0 ){

                cursum = 0;
            }

           
        }
 return maxSum;
    }
};