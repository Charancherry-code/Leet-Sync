class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         
         int n = nums.size();

         //map to store element and index 
         map<int,int>mpp;

          for(int i =0; i<n; i++){ //travelling through nums vector
         int a = nums[i];

        int req = target-a;

              if(mpp.find(req)!= mpp.end()){

                return {mpp[req], i};
              }
             
             mpp[a] = i;


         }

         return{ -1, -1};
    }
};