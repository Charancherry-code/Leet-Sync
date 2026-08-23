class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Track global answer, running max, and running min
        int maxP = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        // Start from index 1 since index 0 initializes the variables
        for(int i = 1; i < n; i++){

            // 1. Swap running products when hitting a negative number
            if(nums[i] < 0){
                swap(currMax, currMin);
            }

            // 2. Update running tracks (choose to start fresh at nums[i] or continue the chain)
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
           
            // 3. Update the overall global maximum found so far
            maxP = max(maxP, currMax);
        }
      
        return maxP;   
    }
};
